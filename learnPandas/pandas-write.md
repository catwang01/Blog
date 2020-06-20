[toc]

## Pandas write 写入比较

结论：
1. to_hdf 比 to_csv 快的不是一点。
2. to_hdf 写压缩文件貌似效率有点低。

```python
import numpy as np
import pandas as pd

#生成9000,0000条数据，9千万条
a = np.random.standard_normal((90000000,4))
df = pd.DataFrame(a)
```

查看数据大小（单位 G）

```python
import sys
sys.getsizeof(df) / 1024 ** 3
```

## to_hdf

### 直接使用 to_hdf

```python
%%time
df.to_hdf("/tmp/test-hdf.h5", key='data')
```

### to_hdf 写入压缩文件

```python
%%time
df.to_hdf("/tmp/test-hdf-compressed.h5", key='data',complevel=4, complib='blosc')
```

## to_pickle

## to_csv

```python
%%time
b.to_csv("/tmp/test-csv.csv")
```

# References
1. [(5条消息)TuShare（3）：使用pandas 压缩存储hdf5文件_freewebsys的专栏-
CSDN博客_pandas to_hdf
压缩](https://blog.csdn.net/freewebsys/article/details/51025044)
