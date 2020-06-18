[toc]

# Tensorflow Dataset

## from_generator

下面的代码展示如何使用 `from_generator` 来生成成对数据集。对于只有 X 而没有 y
的数据集，只需要进行小修改即可。

```python
import tensorflow as tf
import numpy as np

print(tf.__version__) # 2.2.0

# 生成数据集
x_train = np.random.uniform(0, 1, [10, 3])
y_train = np.random.randint(0, 10, [10, ])

# 定义生成器
def batch_generator():
    n_samples = x_train.shape[0]
    for i in range(n_samples):
        yield x_train[i], y_train[i]

# 使用 生成器
train_dataset = tf.data.Dataset.from_generator(batch_generator, (tf.float32, tf.int32))

# 设置epoch为2
train_dataset = train_dataset.repeat(2)
# 这里生成的 dataset 还没有分 batch，使用 .batch() 设置batch_size为 5
train_dataset = train_dataset.batch(5)
for x, y in train_dataset:
    print(x, y)
```

其中有一个坑。 generator 函数返回的应该是一个 tuple 对象，而不是一个 list 对象。

如果将上面的 `batch_generator`
修改成下面的样子，则会报错 `TypeError: `generator` yielded an element that did not match the
expected structure. The expected structure was (tf.float32, tf.int32), but the
yielded element was [array([0.71891118, 0.55713524, 0.83305131]), 2].`

```python
# 定义生成器
def batch_generator():
    n_samples = x_train.shape[0]
    for i in range(n_samples):
        yield [x_train[i], y_train[i]]
```

## from_tensor_slices

```python

import tensorflow as tf
import numpy as np

print(tf.__version__) # 2.2.0

# 生成数据集
x_train = np.random.uniform(0, 1, [10, 3])
y_train = np.random.randint(0, 10, [10, ])


# 使用 生成器
train_dataset = tf.data.Dataset.from_tensor_slices((x_train, y_train))

# 设置epoch为2，设置batch_size为 5
train_dataset = train_dataset.repeat(2).batch(5)
for x, y in train_dataset:
    print(x, y)
```

# References
1. [(1条消息)tf.dataset 使用 python generator 加载和预处理数据，dataset.map
对数据进行额外加工_ONE_SIX_MIX的专栏-
CSDN博客_dataset.map](https://blog.csdn.net/ONE_SIX_MIX/article/details/80633187)
