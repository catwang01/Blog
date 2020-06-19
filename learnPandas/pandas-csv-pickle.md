[toc]

# Python to_csv 和 to_pickle 的比较

```python
先给出结论： to_pickle 比 to_csv 快太多。还是使用 to_pickle 比较好。
```

先 fake 一些数据

```python
import numpy as np
import pandas as pd

df = pd.DataFrame( np.random.rand(10000, 10000))
```

查看一下大小，有小 700 mb

```python
import sys

mb = sys.getsizeof(df) / 1024 ** 2
print("df size is {:.2f}mb".format(mb))
```

```python
%%time
df.to_pickle("/tmp/test.pkl")
```

```python
%%time
df.to_csv("/tmp/test.csv")
```
