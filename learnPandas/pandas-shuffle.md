[toc]

# Pandas shuffle 打乱数据集

```python
import pandas as pd
import numpy as np

df = pd.DataFrame({"col1": np.arange(4),
                "col2": np.random.randn(4)})
df
```

## df.sample

df.sample 是用来随机抽样的，frac表示抽取的比例。如 frac=0.3 表示抽取 30% 的样本（不放回）.

取
frac=1 可以达到 shuffle 的效果

```python
df.sample(frac=1).reset_index(drop=True) # 通常打乱之后需要重新设置 index
```

## 使用 skleran.utils.shuffle

```python
from sklearn.utils import shuffle
```

```python
shuffle(df).reset_index(drop=True)
```


## 使用 np.randon.permutation + df.iloc

```python

shuffled_idx = np.random.permutation(len(df))

df.iloc[shuffled_idx].reset_index(drop=True)
```

# References
1. [Python-Pandas 如何shuffle（打乱）数据？_SCUT_Sam-
CSDN博客](https://blog.csdn.net/qq_22238533/article/details/70917102)
