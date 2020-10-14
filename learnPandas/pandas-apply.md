[toc]

# Pandas apply

注意， 有 Sereis 有 apply 方法，DataFrame 也有 apply 方法。


## 使用多列生成一列

参考 [1]

有时，需要使用多列来组合生成新的一列。可以使用 axis=1

```
df.apply(lambda x: x['col1'] + x['col2'], axis)
```

## 一列返回多列返回多列

两种方式：

### 使用 result_type="expand"

```
df.apply(lambda x: x['col1'] + x['col2'], result_type="expand")
``` 
### 使用 zip

```
zip(*df.apply(lambda x: x['col1'] + x['col2']))
```




# References

1.  [pandas apply使用多列计算生成新的列_wolf1132的博客-CSDN博客_apply函数 两个字段求和 python2.7](https://blog.csdn.net/wolf1132/article/details/90543863)
