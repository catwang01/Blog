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
