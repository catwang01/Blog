[toc]

# pandas 数据的读取与导出

## 导入

### 读取文件

```python
import pandas as pd
from io import StringIO
```

```python
df = pd.read_csv('test.txt', header=None, sep='\t')
```

- 比较关键的是 `header` 参数，没有header的话不设置为None就会报错！

### 读取指定范围

有两个参数可以控制读取指定范围 skiprows 和 nrows。 skiprows 是指定那些行不读取。而 nrows 是指定读取前多少行。

#### 读取前 100 行

**注意，这个 nrows 是不包括 header 所在行的。**

```python
df = pd.read_csv('test.txt', nrows=100)
```

#### skiprows 可以某个区间不读取

```python
df = pd.read_csv('test.txt', skiprowx=10) # 前10行不读取，包括 header行！
```

由于 header 行也会之间具有

#### nrows 和 skiprows 结合读取某个区间

### 指定某行为 header

```python
# 指定第0行为header
df = pd.read_csv('test.csv', header=0)

# 指定第1行为header
df = pd.read_csv('test.csv', header=1)

# 不使用header
df = pd.read_csv("test.csv", header=None)
```

### 设置列名

使用 names 来进行设置

```python
df = pd.read_csv('test.csv', header=0, names=['a', 'b', 'c'])
```

也可以在读入之后使用 df.columns 修改列名

```python
df = pd.read_csv('test.csv', header=0)
df.columns = ['a', 'b', 'c']
```

### encoding 指定编码

```python
pd.read_csv('spam.csv', encoding='latin-1')
```

### 选择部分列

```python
# 可以直接用列名
pd.read_excel('~/Downloads/模拟1数据.xlsx', usecols=['UP_GPS'])

# 也可以用序号，也可以交换顺序
pd.read_excel('~/Downloads/模拟1数据.xlsx', usecols=[4, 3]) 
```

### 指定类型

```python
data = 'a,b,c\n1,2,3\n4,5,6\n7,8,9'
#指定每列数据都为str
df = pd.read_csv(StringIO(data), dtype=object)

#分列指定
df = pd.read_csv(StringIO(data), dtype={'b': object, 'c': np.float64})
df.dtypes # a int64, b object, c float64 
```

### 日期解码

```python
data = """Id,date,val
4,2020-04-21,6
5,2020-04-22,6
7,2020-04-23,9
"""
#指定每列数据都为str
df = pd.read_csv(StringIO(data), dtype=object)

#分列指定
df = pd.read_csv(StringIO(data), parse_dates=[1]) # 1 表示下标为1的列。即第2列
df.date
```

## 导出

```python
df.to_excel('output.xlsx') 
df.to_csv('output.csv')
df.to_csv('output.csv', index=False, header=False)
```

![](https://gitee.com/EdwardElric_1683260718/picture_bed/raw/master/img/20200715201842.png)

# References
1. [pandas21 读csv文件read_csv（3.dtypes指定列数据类型）（详细 tcy）_Python_tcy-阿春-
CSDN博客](https://blog.csdn.net/tcy23456/article/details/85290575)
2. [Python Pandas read_csv跳过行，但保留头 - IT屋-程序员软件开发技术分享社区](https://www.it1352.com/584705.html)
