#coding=utf-8
import tensorflow as tf

with tf.variable_scope("foo"):
    v = tf.get_variable("v", [1], initializer=tf.constant_initializer(1.0))

# with tf.variable_scope("foo"):
#     v = tf.get_variable("v", [1])

with tf.variable_scope("foo", reuse=True):
    v1 = tf.get_variable("v", [1])
    print v == v1     # True

# with tf.variable_scope("bar", reuse=True):
#     v = tf.get_variable("v", [1])

with tf.variable_scope("root"):
    print tf.get_variable_scope().reuse     #  不指定 reuse 时候默认为 False
    with tf.variable_scope("foo", reuse=True):
        print tf.get_variable_scope().reuse #  外层指定了 reuse 为 True，因此此处为 True
        with tf.variable_scope("bar"):
            print tf.get_variable_scope().reuse # 新建一个上下文管理器但不指定 reuse，则与外层保持一致，为 True
    print tf.get_variable_scope().reuse     #  回退到最外层，为 False

v1 = tf.get_variable("v", [1])
print v1.name

with tf.variable_scope("foo", reuse=True):
    v2 = tf.get_variable("v", [1])    # foo/v:0
    print v2.name

with tf.variable_scope("foo"):
    with tf.variable_scope("bar"):
        v3 = tf.get_variable("v", [1])  # foo/bar/v:0  命名空间可以嵌套
        print v3.name
    v4 = tf.get_variable("v1", [1])   # foo/v1
    print v4.name

with tf.variable_scope("", reuse=True):      # 名称为空的命名空间
    v5 = tf.get_variable("foo/bar/v", [1])   # 通过带命名空间的变量名获取其他命名空间下的变量
    print v5 == v3   # True
    v6 = tf.get_variable("foo/v1", [1])
    print v6 == v4   # True

