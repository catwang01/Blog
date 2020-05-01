[TOC]

# Pandas DataFrame

## 索引

### 列

```
import pandas as pd
import numpy as np

df = pd.DataFrame({'c1': [1,2,3],
                  'c2': [4,5,6],
                  'c3': [7,8,9]})
df['c3']
```

### 行

```
import pandas as pd
import numpy as np

df = pd.DataFrame(np.arange(9).reshape(3,3), columns=['c1', 'c2', 'c3'],  index=['r1', 'r2', 'r3'])

df[0:2] # 取 0、1 行
df['r1':'r3'] # 取 'r1' 'r2' 'r3' 行，注意这里包含 'r3'
```

### loc 取行列

```
import pandas as pd
import numpy as np

df = pd.DataFrame(np.arange(9).reshape(3,3), columns=['c1', 'c2', 'c3'],  index=['r1', 'r2', 'r3'])

# 取行
df.loc[['r1'], :]
# 取列
df.loc[:, ['c3']]
# 取行列
df.loc[['r1':'r3'], ['c3']]
```


## reindex

```
import pandas as pd
import numpy as np

df = pd.DataFrame(np.arange(9).reshape(3,3), columns=['c1', 'c2', 'c3'],  index=['r1', 'r2', 'r3'])
df
df.reindex(['r2', 'r1', 'r4']) # ‘r4' 没有默认填充为 NaN
df.reindex(['r2', 'r1', 'r4'], fill_value=1) # 'r4' 填充为 1
```


## 其它

## df.dtypes 查看各列数据类型

##### dataframe的行名和列名

```
df.index 是行名
df.columns 是列名
```
##### dataframe 修改列名

>问题：
有一个DataFrame，列名为：['$a', '$b', '$c', '$d', '$e']
现需要改为：['a', 'b', 'c', 'd', 'e']
有何办法？

```
import pandas as pd
df = pd.DataFrame({'$a': [1], '$b': [1], '$c': [1], '$d': [1], '$e': [1]})
```
1. method1 直接替换

```
# method1
df.columns = [each.strip('$') for each in df.columns]
```

2. method2 使用rename方法

如果 inplace=False，会返回修改列名后的df，原始df不变；如果inplace=True，则会返回None，原始df会被修改

```
# 传入一个list
df.rename(columns=lambda x: x.strip('$'), inplace=True)

# 传入一个dict，可以对特定的列改名
df.rename(columns={'$a': 'a', '$b': 'b', '$c': 'c', '$d': 'd', '$e': 'e'}, inplace=True) 
```

### astype 修改数据类型

```
# 记得要赋值！
df = df.astype(float)
```

### 添加行、列

- **注意直接使用 1 维 array or list 来插会插入列而不是行，需要转化为2维，用[mylist]**
- 注意和list的append不同，df.append不会影响df的值，**需要赋值给df**

```
newdf = df.append(newrow, ignore_index=True)
```

### DataFrame 遍历行列

```
# 遍历列
for index, column in df.iteritems():
    print(index)    # 列索引
    print(column)

for index, row in df.iterrows():
    print(index)    # 行索引
    print(row)
```

##### 关于 nan

```
df.isnull()
df.dropna()
```


### 引用行、列

- pandas 中区别行列的方法
    - 要理解dataframe中行表示一个样本，列表示一个变量。
        - df.mean() 这个肯定默认是对列进行均值，因为如果对一行求均值的话如何这些变量不是同一个数量级的，那些这种操作没有意义。
        - df.plot 这个肯定默认对每一列画一条线，如果对一行画出一条线，那么将不同的变量画在同一条线上没有意义。


```
# 引用行
df.iloc[1] 
# 引用列
df.iloc[:, 1]
```

