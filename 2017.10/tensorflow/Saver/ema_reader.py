import tensorflow as tf

v = tf.Variable(0, dtype=tf.float32, name="v")

# saver = tf.train.Saver({"v/ExponentialMovingAverage": v})
# with tf.Session() as sess:
#     saver.restore(sess, "./tmp/test.ckpt")
#     print sess.run(v)

ema = tf.train.ExponentialMovingAverage(0.98)

print ema.variables_to_restore()

saver = tf.train.Saver(ema.variables_to_restore())
with tf.Session() as sess:
    saver.restore(sess, "./tmp/test.ckpt")
    print sess.run(v)
