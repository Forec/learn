#coding=utf-8

from __future__ import print_function
import sys
import threading

from grpc.beta import implementations
import numpy
import tensorflow as tf

from tensorflow_serving.apis import predict_pb2
from tensorflow_serving.apis import prediction_service_pb2
from tensorflow.examples.tutorials.mnist import input_data

tf.app.flags.DEFINE_integer('concurrency', 1, 'maximum number of concurrent infrence requests')
tf.app.flags.DEFINE_integer('num_tests', 100, 'Number of test images')
tf.app.flags.DEFINE_string('server', '', 'PredicationService host:port')
tf.app.flags.DEFINE_string('work_dir', '/tmp', 'Working directory.')
FLAGS = tf.app.flags.FLAGS

class ResultCounter(object):
    def __init__(self, num_tests, concurrency):
        self._num_tests = num_tests
        self._concurrency = concurrency
        self._error = 0
        self._done = 0
        self._active = 0
        self._condition = threading.Condition()

    def inc_error(self):
        with self._condition:
            self._error += 1

    def inc_done(self):
        with self._condition:
            self._done += 1
            self._condition.notify()

    def dec_active(self):
        with self._condition:
            self._active -= 1
            self._condition.notify()

    def get_error_rate(self):
        with self._condition:
            while self._done != self._num_tests:
                self._condition.wait()
            return self._error / float(self._num_tests)

    def throttle(self):
        with self._condition:
            while self._active == self._concurrency:
                self._condition.wait()
            self._active += 1

def _create_rpc_callback(label, result_counter):
    def _callback(result_future):
        exception = result_future.exception()
        if exception:
            result_counter.inc_error()
            print(exception)
        else:
            sys.stdout.write('.')
            sys.stdout.flush()
            response = numpy.array(
                result_future.result().outputs['scores'].float_val)
            prediction = numpy.argmax(response)
            if label != prediction:
                result_counter.inc_error()
        result_counter.inc_done()
        result_counter.dec_active()
    return _callback

def do_inference(hostport, work_dir, concurrency, num_tests):
    test_data_set = input_data.read_data_sets(work_dir).test
    host, port = hostport.split(':')
    channel = implementations.insecure_channel(host, int(port))
    stub = prediction_service_pb2.beta_create_PredictionService_stub(channel)
    result_counter = ResultCounter(num_tests, concurrency)
    for _ in range(num_tests):
        request = predict_pb2.PredictRequest()
        request.model_spec.name = 'mnist'
        request.model_spec.signature_name = 'predict_images'
        image, label = test_data_set.next_batch(1)
        request.inputs['images'].CopyFrom(
            tf.contrib.util.make_tensor_proto(image[0], shape=[1, image[0].size]))
        result_counter.throttle()
        result_future = stub.Predict.future(request, 5.0)  # 5 seconds
        result_future.add_done_callback(
            _create_rpc_callback(label[0], result_counter))
    return result_counter.get_error_rate()

def main(_):
    if FLAGS.num_tests > 10000:
        print("too much tests")
        return
    if not FLAGS.server:
        print('must specify server host:port')
        return
    error_rate = do_inference(FLAGS.server, FLAGS.work_dir, FLAGS.concurrency, FLAGS.num_tests)
    print('Inference error rate: %s%%' % (error_rate * 100))

if __name__ == '__main__':
    tf.app.run()
