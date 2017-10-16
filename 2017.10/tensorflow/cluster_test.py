#coding=utf-8
import tensorflow as tf
import numpy as np

ps_hosts = ["localhost:2222", "localhost:2223"]
worker_hosts = ["localhost:2224", "localhost:2225", "localhost:2226"]
cluster = tf.train.ClusterSpec({"ps": ps_hosts, "worker": worker_hosts})

tf.app.flags.DEFINE_string("job_name", "worker", "One of 'ps', 'worker'")
tf.app.flags.DEFINE_integer("task_index", 0, "Index of task within the job")

FLAGS = tf.app.flags.FLAGS

def main(_):
    server = tf.train.Server(cluster, job_name=FLAGS.job_name, task_index=FLAGS.task_index)
    if FLAGS.job_name == 'ps':
        # 若工作名称为 param server，则在此挂起
        server.join()
    with tf.device(tf.train.replica_device_setter(
            worker_device="/job:worker/task:%d" % FLAGS.task_index,
            cluster=cluster)):   # 通过 replica_device_setter 来设置计算所在的设备
        x_data = tf.placeholder(tf.float32, [100])
        y_data = tf.placeholder(tf.float32, [100])
        W = tf.Variable(tf.random_uniform([1], -1.0, 1.0))
        b = tf.Variable(tf.zeros([1]))
        y = W * x_data + b
        loss = tf.reduce_mean(tf.square(y - y_data))

        global_step = tf.Variable(0, name="global_step", trainable=False)
        optimizer = tf.train.GradientDescentOptimizer(0.1)
        train_op = optimizer.minimize(loss, global_step=global_step)

        tf.summary.scalar('cost', loss)
        summary_op = tf.summary.merge_all()
        init_op = tf.global_variables_initializer()

    hooks = [tf.train.StopAtStepHook(last_step = 4000)]
    with tf.train.MonitoredTrainingSession(master="grpc://" + worker_hosts[FLAGS.task_index],
                                           is_chief=(FLAGS.task_index==0),
                                           checkpoint_dir="./tmp/tf_train_logs",
                                           save_checkpoint_secs=None,
                                           hooks=hooks) as mon_sess:    # tf.train.Supervisor 也可以统一管理队列操作、模型保存、日志输出及会话的生成
        while not mon_sess.should_stop():
            train_x = np.random.rand(100).astype(np.float32)
            train_y = train_x * 0.1 + 0.3
            _, step, loss_v, weight, biase = mon_sess.run([train_op, global_step, loss, W, b], feed_dict={x_data: train_x, y_data: train_y})
            if step % 100 == 0:
                print "step: %d, weight: %f, biase: %f, loss: %f" % (step, weight, biase, loss_v)
        print "Optimization finished"

if __name__ == '__main__':
    print "Start main"
    tf.app.run()
    print "End main"

