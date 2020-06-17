[toc]

# Sklearn OneHotEncoder


## 参数

- categories:
    list 指定每个 feature 的 categories

- sparse:
default: True
    函数默认返回的是一个 `scipy.sparse.csr.csr_matrix`。 sparse=False 可以返回一个
`np.ndarray`

## 实战

### categories

```python
import numpy as np
from sklearn.preprocessing import OneHotEncoder
```

```python
# 生成数据
np.random.seed(123)
n_class = 4
x = np.random.randint(0, n_class, size=(5,1))
x
```

```python
encoder = OneHotEncoder(categories=[[0,1,2,3]], sparse=False)
transformed = encoder.fit_transform(x)
# 返回的是 scipy.sparse.csr.csr_matrix
transformed
```

# References

1. [sklearn.preprocessing.OneHotEncoder — scikit-learn 0.23.1
documentation](https://scikit-
learn.org/stable/modules/generated/sklearn.preprocessing.OneHotEncoder.html)
