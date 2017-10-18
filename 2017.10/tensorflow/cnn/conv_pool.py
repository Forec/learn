import tensorflow as tf
import numpy as np

M = np.array([
    [[1], [-1], [0]],
    [[-1], [2], [1]],
    [[0], [2], [-2]]
])

print "Matrix shape is: ", M.shape

# 四维矩阵，前 2 维表示过滤器尺寸，第三维表示当前层的深度，第四维表示过滤器深度
filter_weight = tf.get_variable("weights", [2, 2, 1, 1], initializer=tf.constant_initializer([[1, 01], [0, 2]]))
# biases 的维度和权重矩阵的最后一维大小相等
biases = tf.get_variable('biases', [1], intializer=tf.constant_initializer(1))

M = np.asarray(M, dtype='float32')
M = M.reshape(1, 3, 3, 1)

x = tf.placeholder('float32', [1, None, None, 1])  # 输入数据
conv = tf.nn.conv2d(x, filter_weight, strides=[1, 2, 2, 1], padding='SAME')  # 卷积层的前向传播
bias = tf.nn.bias_add(conv, biases)
pool = tf.nn.avg_pool(x, ksize=[1, 2, 2, 1], strides=[1, 2, 2, 1], padding='SAME')
with tf.Session() as sess:
    tf.global_variables_initializer().run()
    convoluted_M = sess.run(bias, feed_dict={x: M})   # 卷积层
    pooled_M = sess.run(pool, feed_dict={x: M})       # 池化层
    print "convoluted_M: \n", convoluted_M
    print "pooled_M: \n", pooled_M
