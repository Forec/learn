import tensorflow as tf

reader = tf.train.NewCheckpointReader("./tmp/test.ckpt")
all_variables = reader.get_variable_to_shape_map()
for variable in all_variables:
    print variable, all_variables[variable]

print "Value for variable v is ", reader.get_tensor("v")
