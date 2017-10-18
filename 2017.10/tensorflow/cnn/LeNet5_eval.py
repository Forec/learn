#-*-coding:utf-8-*-

import time
import tensorflow as tf
from tensorflow.examples.tutorials.mnist import input_data
import numpy as np
import LeNet5_train
import LeNet5_inference

EVAL_INTERVAL_SECS = 10

def evaluate(mnist):
    with tf.Graph().as_default() as g:
        x = tf.placeholder(tf.float32, [
            mnist.validation.num_examples,
            LeNet5_inference.IMAGE_SIZE,
            LeNet5_inference.IMAGE_SIZE,
            LeNet5_inference.NUM_CHANNELS], name='x-input')
        y_ = tf.placeholder(tf.float32, [None, LeNet5_inference.OUTPUT_NODE], name='y-input')
        reshaped_xs = np.reshape(mnist.validation.images, (
            mnist.validation.num_examples,
            LeNet5_inference.IMAGE_SIZE,
            LeNet5_inference.IMAGE_SIZE,
            LeNet5_inference.NUM_CHANNELS))
        validate_feed = {x: reshaped_xs, y_: mnist.validation.labels}

        y = LeNet5_inference.inference(x, False, None)
        correct_prediction = tf.equal(tf.argmax(y, 1), tf.argmax(y_, 1))
        accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))

        variable_averages = tf.train.ExponentialMovingAverage(LeNet5_train.MOVING_AVERAGE_DECAY)
        # 用变量重命名的方式加载模型，因此前向传播的过程中就不需要调用 ema.average 这样的方法来获取平均值，而是可以
        # 完全公用 mnist_inference 中定义的前向传播过程
        variables_to_restore = variable_averages.variables_to_restore()
        saver = tf.train.Saver(variables_to_restore)

        while True:
            with tf.Session() as sess:
                ckpt = tf.train.get_checkpoint_state(LeNet5_train.MODEL_SAVE_PATH)
                if ckpt and ckpt.model_checkpoint_path:
                    saver.restore(sess, ckpt.model_checkpoint_path)
                    global_step = ckpt.model_checkpoint_path.split('/')[-1].split('-')[-1]
                    accuracy_score = sess.run(accuracy, feed_dict=validate_feed)
                    print("After %s training step(s), validation accuracy = %g" % (global_step, accuracy_score))
                else:
                    print("No checkpoint file found")
                    return
            time.sleep(EVAL_INTERVAL_SECS)

def main(argv=None):
    mnist = input_data.read_data_sets("../MNIST_DATA", one_hot=True)
    evaluate(mnist)

if __name__ == '__main__':
    main()
