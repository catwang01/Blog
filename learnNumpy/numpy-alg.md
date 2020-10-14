
[toc]

# Numpy linalg

## linalg

### np.linalg.det

```
X = np.arange(4).reshape(2,2)
np.linalg.det(X)
```

### np.linalg.norm

```
x = np.arange(5)

np.linalg.norm(x, ord=1)
```

对于矩阵来说，可以计算每行/每列的 norm

```
A = np.ones((3, 4))

np.linalg.norm(A, ord=2) # 3.4641016151377548

# 按行计算 norm
np.linalg.norm(A, ord=2, axis=1) [2.0, 2.0, 2.0]

# 相当于
[np.linalg.norm(row, ord=2) for row in A]

# 按列计算 norm
np.linalg.norm(A, ord=2, axis=0)
```

![2b95529972404a679b8f997a811d9a5a.png](evernotecid://7E3AE0DC-DC71-4DDC-9CC8-0C832D6C11C2/appyinxiangcom/22483756/ENResource/p10531)

### np.linalg.inv

```
x = np.array([[1,2],[3,4]])
np.linalg.inv(x)
```

## 矩阵操作

### np.matmul 矩阵乘法

```python
import numpy as np

X = np.random.normal(size=(3,2))
y = np.random.normal(size=(2,4))

np.matmul(X, y) # 直接计算 X * y 会报错
```

    array([[ 1.73673717, -2.84289069, -0.64824864,  3.80927957],
           [-1.13449018,  2.62934941, -0.28690457, -3.23659914],
           [-0.15219046,  0.45402799, -0.13166891, -0.5323383 ]])


X * y 的写法会进行广播操作


```python
x = np.random.normal(size=(3, 1))
y = np.random.normal(size=(1, 3))

x * y == np.matmul(x, y)
```

    array([[ True,  True,  True],
           [ True,  True,  True],
           [ True,  True,  True]])

### np.mean

- 注意我们一般将一行看成一个instance，此时计算样本均值时必须添加 `axis=0` 参数，否则会默认对整个矩阵求均值

```
import numpy as np

X = np.random.normal(size=[3, 4])

np.mean(X, axis=0)
```

### np.cov


- 注意我们一般将一行看成一个instance，此时计算样本方差时必须添加 `rowraw=False` 参数，否则会默认将列看成一个 instance 来计算方差

```
import numpy as np

X = np.random.normal(size=[3, 4])

np.cov(X, rowraw=False)
```


# References
1. [numpy.linalg.inv — NumPy v1.17 Manual](https://docs.scipy.org/doc/numpy/reference/generated/numpy.linalg.inv.html)
