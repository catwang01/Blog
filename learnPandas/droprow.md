[toc]

# Pandas DataFrame 删除行列

## 使用 drop

```
df = pd.DataFrame(np.arange(12).reshape(3,4), columns=['A', 'B', 'C', 'D'])
```

数据长这个样子

```
   A   B   C   D

0  0   1   2   3

1  4   5   6   7

2  8   9  10  11
```

## 删除行


```
# method1
df.drop(['B', 'C'], axis=1)
# method2
df.drop(columns=['B', 'C'])
```
第一种方法下删除column一定要指定axis=1,否则会报错

```
df.drop(['B', 'C'])

ValueError: labels ['B' 'C'] not contained in axis
```

## 删除列


```
# method1
df.drop([0, 1])

# method2
df.drop(index=[0, 1])
```

## 按照条件筛选

```
x = pd.DataFrame({"col": [1,2,3]})
def delete1(x):
    x.drop(x.index[x['col']==1], inplace=True)

delete1(x)
print(x)
```

下面这种无法达到目的

```
x = pd.DataFrame({"col": [1,2,3]})
def delete2(x):
    x = x[x['col']==1]
delete2(x)
print(x)
```



# References
1. [Python中pandas dataframe删除一行或一列：drop函数_Python_海晨威-CSDN博客](https://blog.csdn.net/songyunli1111/article/details/79306639)
