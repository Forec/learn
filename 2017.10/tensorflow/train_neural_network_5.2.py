#coding=utf-8
import tensorflow as tf
from tensorflow.examples.tutorials.mnist import input_data

INPUT_NODE = 784
OUTPUT_NODE = 10
LAYER1_NODE = 500   # 隐藏层的节点数，这里只使用有一个隐藏层的网络结构
BATCH_SIZE = 100    # 每一次训练时使用的 batch 数据集大小

LEARNING_RATE_BASE = 0.8    # 基础学习率
LEARNING_RATE_DECAY = 0.99  # 学习率的衰减率
REGULARAZTION_RATE = 0.0001 # 描述模型复杂度的正则化项在损失函数中的系数
TRAINING_STEPS = 5000       # 训练轮数
MOVING_AVERAGE_DECAY = 0.99 # 滑动平均衰减率

def inference(input_tensor, avg_class, weights1, biases1, weights2, biases2):
    if avg_class is None:
        layer1 = tf.nn.relu(tf.matmul(input_tensor, weights1) + biases1)
        return tf.matmul(layer1, weights2) + biases2
    else:
        layer1 = tf.nn.relu(tf.matmul(input_tensor, avg_class.average(weights1)) + avg_class.average(biases1))
        return tf.matmul(layer1, avg_class.average(weights2)) + avg_class.average(biases2)
    # 这里输出层的前向传播结果不需要加入激活函数（relu）。因为在计算 loss 的时候会一并计算 softmax（sparse_softmax_cross_entropy_with_logits），softmax 求出各个标签的概率，信息熵损失将概率变为 loss 值。而且不加入 softmax 也不会影响预测结果，因为预测时使用的是不同类别对应节点输出值的相对大小。

# 理解命名空间中的 reuse：要明确，tensorflow 的计算图表示了整个计算流程中张量的流动方向， y = inference2(x, False) 表示的是每次计算流程中的一个节点，这个节点是唯一存在的，在整个计算图的生命周期中，这个节点从创建之后起，就处于计算状态，它只执行计算操作，它只负责对到来的数据流做处理，并不需要在数据流到来时再初始化环境等，因此这里虽然 reuse 为 False，但它在计算过程中只会对 weights 和 biases 做处理并将结果给后续的节点，而不会再不断的创建／获取变量。只有计算操作。一旦启动，与状态无关。
def inference2(input_tensor, reuse=False):
    # 定义第一层精神网络的变量和前向传播过程
    with tf.variable_scope('layer1', reuse=reuse):
        # 根据传进来的 reuse 来判断创建新变量还是使用已经创建好的。第一次构造时需要创建新的变量，之后每次调用这个函数都使用 reuse=True 就不需要将变量传进来
        weights = tf.get_variable("weights", [INPUT_NODE, LAYER1_NODE], initializer=tf.truncated_normal_initializer(stddev=0.1))
        biases = tf.get_variable("biases", [LAYER1_NODE], initializer=tf.constant_initializer(0.0))
        layer1 = tf.nn.relu(tf.matmul(input_tensor, weights) + biases)
    with tf.variable_scope('layer2', reuse=reuse):
        weights = tf.get_variable("weights", [LAYER1_NODE, OUTPUT_NODE], initializer=tf.truncated_normal_initializer(stddev=0.1))
        biases = tf.get_variable("biases", [OUTPUT_NODE], initializer=tf.constant_initializer(0.0))
        layer2 = tf.matmul(layer1, weights) + biases
    return layer2

def train(mnist):
    x = tf.placeholder(tf.float32, [None, INPUT_NODE], name='x-input')
    y_ = tf.placeholder(tf.float32, [None, OUTPUT_NODE], name='y-input')

    # 隐藏层的参数
    weights1 = tf.Variable(tf.truncated_normal([INPUT_NODE, LAYER1_NODE], stddev=0.1))
    biases1 = tf.Variable(tf.constant(0.1, shape=[LAYER1_NODE]))
    # 输出层的参数
    weights2 = tf.Variable(tf.truncated_normal([LAYER1_NODE, OUTPUT_NODE], stddev=0.1))
    biases2 = tf.Variable(tf.constant(0.1, shape=[OUTPUT_NODE]))

    # 计算不包含滑动平均类的前向传播效果
    # y = inference(x, None, weights1, biases1, weights2, biases2)

    # 定义训练轮数及相关的滑动平均类
    global_step = tf.Variable(0, trainable=False)
    variable_averages = tf.train.ExponentialMovingAverage(MOVING_AVERAGE_DECAY, global_step)
    variable_averages_op = variable_averages.apply(tf.trainable_variables())
    average_y = inference2(x)#inference(x, variable_averages, weights1, biases1, weights2, biases2)

# 在这里输出一下所有需要训练的参数，包括 layer1/weights, layer1/biases, layer2/weights, layer2/biases
#    print tf.trainable_variables()
#    return

    # 计算交叉熵及其平均值
    cross_entropy = tf.nn.sparse_softmax_cross_entropy_with_logits(logits=average_y, labels=tf.argmax(y_, 1))
    cross_entropy_mean = tf.reduce_mean(cross_entropy)

    # 计算损失函数
    regularizer = tf.contrib.layers.l2_regularizer(REGULARAZTION_RATE)
    regularaztion = regularizer(weights1) + regularizer(weights2)
    loss = cross_entropy_mean + regularaztion

    # 指数衰减的学习率
    learning_rate = tf.train.exponential_decay(
        LEARNING_RATE_BASE,
        global_step,  # 这里的 global_step 指的是当前训练到多少轮，该参数在 minimize 中传入，会自动更新
        mnist.train.num_examples / BATCH_SIZE,
        LEARNING_RATE_DECAY,
        staircase=True)

    # 优化损失函数，minimize 函数会自动更新 global_step
    train_step = tf.train.GradientDescentOptimizer(learning_rate).minimize(loss, global_step=global_step)

    # 反向传播更新参数和每一个参数的滑动平均值
    # 因为每次过一遍数据都需要通过反向传播更新神经网络中的参数、又要更新每一个参数的滑动平均值，因此可以将这
    # 两个操作（train_step 和 variable_averages_op）作为一个列表来维护。control_dependencies 提供了一个依赖环境，
    # 因此下面的 train_op 就是 no_op，下面两行也可以写成
    # train_op = tf.group(train_step, variable_averages_op)
    with tf.control_dependencies([train_step, variable_averages_op]):
        train_op = tf.no_op(name='train')

    # tf.argmax 第二个参数表示选取最大值的操作在第几个维度进行，为 1 表示仅每一行内选取最大值，返回最大值对应的下标
    corrent_prediction = tf.equal(tf.argmax(average_y, 1), tf.argmax(y_, 1))
    # 先转换为实数，再计算平均值（每个值不是 1 就是 0）
    accuracy = tf.reduce_mean(tf.cast(corrent_prediction, tf.float32))

    # accuracy 等结果是根据预测结果和真实结果唯一确定的值，只用于评估当前模型的预测能力
    # weights、biases 等变量是 trainable 的，每当运行 train_op 的时候，tensorflow 都会自动更新这部分变量

    with tf.Session() as sess:
        tf.global_variables_initializer().run()
        # 验证数据，每训练过一定时间之后，通过这个固定的验证数据来估计训练精确度，以停止训练
        validate_feed = {x: mnist.validation.images, y_: mnist.validation.labels}
        # 测试数据，这部分数据在训练时不可见，模拟真实环境下评估模型的优劣
        test_feed = {x: mnist.test.images, y_: mnist.test.labels}

        for i in range(TRAINING_STEPS):
            if i % 1000 == 0:
                validate_acc = sess.run(accuracy, feed_dict = validate_feed)
                print("After %d training step(s), validation accuracy using average model is %g " % (i, validate_acc))
            xs, ys = mnist.train.next_batch(BATCH_SIZE)  # 产生下一轮训练使用的 batch 数据
            sess.run(train_op, feed_dict={x: xs, y_:ys}) # 运行训练过程
        # 训练结束后，用测试数据集判断预测结果
        test_acc = sess.run(accuracy, feed_dict={x:xs, y_:ys})
        print(("After %d training step(s), test accuracy using average model is %g" % (TRAINING_STEPS, test_acc)))

def main(argv=None):
    mnist = input_data.read_data_sets("./MNIST_DATA", one_hot=True)
    train(mnist)

if __name__ == '__main__':
    main()
