[toc]

# pandas 数据的读取与导出

## 导入

### 读取文件

- TXT文件和CSV的文件的区别是：前者使用\t作为分隔符，后者使用,作为分隔符。

```
df = pd.read_csv('test.txt', header=None, sep='\t')
```

- 比较关键的是 `header` 参数，没有header的话不设置为None就会报错！

### 读取前 100 行

```
df = pd.read_csv('test.txt', nrow=100)
```

### 指定某行为 header

```
# 指定第0行为header
df = pd.read_csv('test.csv', header=0)

# 指定第1行为header
df = pd.read_csv('test.csv', header=1)

# 不使用header
df = pd.read_csv("test.csv", header=None)
```

### 设置列名

使用 names 来进行设置

```
df = pd.read_csv('test.csv', header=0, names=['a', 'b', 'c'])
```

也可以在读入之后使用 df.columns 修改列名

```
df = pd.read_csv('test.csv', header=0)
df.columns = ['a', 'b', 'c']
```

### encoding 指定编码 

```
pd.read_csv('spam.csv', encoding='latin-1')
```

### 选择部分列

```
# 可以直接用列名
pd.read_excel('~/Downloads/模拟1数据.xlsx', usecols=['UP_GPS'])

# 也可以用序号，也可以交换顺序
pd.read_excel('~/Downloads/模拟1数据.xlsx', usecols=[4, 3]) 
```

### 指定类型

```
data = 'a,b,c\n1,2,3\n4,5,6\n7,8,9'
#指定每列数据都为str
df = pd.read_csv(StringIO(data), dtype=object)

#分列指定
df = pd.read_csv(StringIO(data), dtype={'b': object, 'c': np.float64})
df.dtypes # a int64, b object, c float64 
```

## 导出

```
df.to_excel('output.xlsx') 
df.to_csv('output.csv')
df.to_csv('output.csv', index=False, header=False)
```

![4ecdd130e866876cff6d37787c9002e0.png](evernotecid://7E3AE0DC-DC71-4DDC-9CC8-0C832D6C11C2/appyinxiangcom/22483756/ENResource/p10619)

# References
1. [pandas21 读csv文件read_csv（3.dtypes指定列数据类型）（详细 tcy）_Python_tcy-阿春-CSDN博客](https://blog.csdn.net/tcy23456/article/details/85290575)
