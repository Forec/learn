#coding=utf-8
import tensorflow as tf
import numpy as np

#ps_hosts = ["localhost:2222"]
worker_hosts = ["localhost:2224", "localhost:2225", "localhost:2226"]
cluster = tf.train.ClusterSpec({"worker": worker_hosts})#, "ps": ps_hosts})

tf.app.flags.DEFINE_string("job_name", "worker", "One of 'ps', 'worker'")
tf.app.flags.DEFINE_integer("task_index", 0, "Index of task within the job")

FLAGS = tf.app.flags.FLAGS

def main(_):
    tf.reset_default_graph()
    server = tf.train.Server(cluster, job_name=FLAGS.job_name, task_index=FLAGS.task_index)
    if FLAGS.job_name == 'ps':
        # 若工作名称为 param server，则在此挂起
        server.join()
    is_chief = (FLAGS.task_index == 0)
    with tf.device(tf.train.replica_device_setter(   # 图间分布式
            worker_device="/job:worker/task:%d" % FLAGS.task_index,
            cluster=cluster)):   # 通过 replica_device_setter 来设置计算所在的设备
        x_data = tf.placeholder(tf.float32, [100], name='x-input')
        y_data = tf.placeholder(tf.float32, [100], name='y-input')
        with tf.device("/job:worker/task:%d" % FLAGS.task_index):
            W = tf.Variable(tf.random_uniform([1], -1.0, 1.0), name="W")
            b = tf.Variable(tf.zeros([1]), name="b")
            y = W * x_data + b
            loss = tf.reduce_mean(tf.square(y - y_data))
            global_step = tf.Variable(0, name="global_step", trainable=False)
            opt = tf.train.SyncReplicasOptimizer(
                tf.train.GradientDescentOptimizer(0.1),
                replicas_to_aggregate=3,
                total_num_replicas=3)
            train_op = opt.minimize(loss, global_step=global_step)
        saver = tf.train.Saver()
        summary_op = tf.summary.merge_all()
        init_op = tf.global_variables_initializer()

        if is_chief:
            chief_queue_runner = opt.get_chief_queue_runner()
            init_tokens_op = opt.get_init_tokens_op(0)

        # sv = tf.train.Supervisor(is_chief=is_chief,
        #                          logdir='./tmp/tf_train_logs',
        #                          init_op=init_op,
        #                          summary_op=summary_op,   # 日志生成操作
        #                          saver=saver,             # 用于保存模型的saver
        #                          global_step=global_step, # 当前迭代的轮数
        #                          save_model_secs=60,      # 保存模型的时间间隔
        #                          save_summaries_secs=60)  # 日志输出的时间间隔
        # sess_config = tf.ConfigProto(allow_soft_placement=True, log_device_placement=False)
        # sess = sv.prepare_or_wait_for_session(server.target, config=sess_config)
        # print "I have intialized all variables"

        # if is_chief:
        #     sv.start_queue_runners(sess, [chief_queue_runner])
        #     sess.run(init_tokens_op)
        hooks = [tf.train.StopAtStepHook(last_step = 4000)]
        print "ready"
        with tf.train.MonitoredTrainingSession(master="grpc://" + worker_hosts[FLAGS.task_index],
                                           is_chief=(FLAGS.task_index==0),
                                           checkpoint_dir="./tmp/tf_train_logs",
                                           save_checkpoint_secs=None,
                                           hooks=hooks) as sess:    # tf.train.Supervisor 也可以统一管理队列操作、模型保存、日志输出及会话的生成
            sess.run(init_op)
            print "Ready to start training"
            while not sess.should_stop():
                train_x = np.random.rand(100).astype(np.float32)
                train_y = train_x * 0.1 + 0.3
                _, step, loss_v, weight, biase = sess.run([train_op, global_step, loss, W, b], feed_dict={x_data: train_x, y_data: train_y})
                if step > 0 and step % 100 == 0:
                    print "step: %d, weight: %f, biase: %f, loss: %f" % (step, weight, biase, loss_v)
                if step > 4000:
                    print "I am going to break"
                    break

        print "Optimization finished"

if __name__ == '__main__':
    tf.app.run()
