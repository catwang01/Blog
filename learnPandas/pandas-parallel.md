[toc]

# Pandas pandarallel

据说使用 pandas pandarallel 会加速。但是我测试为什么没有加速呢。。

```python
import pandas as pd
import numpy as np
from pandarallel import pandarallel

pandarallel.initialize(nb_workers=4)

def func(x):
    return x ** 3

df = pd.DataFrame(np.random.rand(10000, 10000))
# 使用很简单
result = df.parallel_apply(func, axis=1)
```

```python
%%time 
result = df.apply(func, axis=1)
```

```python
%%time
result = df.parallel_apply(func, axis=1)
```

```python
%%time
result = df.parallel_apply(lambda x: x**3, axis=1)
```

```python
import math
df_size = int(5e4)
df = pd.DataFrame(dict(a=np.random.randint(1, 8, df_size),b=np.random.rand(df_size)))

def func(x):
    return math.sin(x.a**2) + math.sin(x.b**2)

```

```python
%%time
res = df.apply(func, axis=1)
```

```python
%%time
res_parallel = df.parallel_apply(func, axis=1)
```
