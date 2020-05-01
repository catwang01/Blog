[toc]


# Pandas Nan

## fillna()

```
df.fillna(method='pad')
```

```
# 缺失值用3来填充
df.fillna(3, inplace=True)
```

## isna()
df.isna() 查看是否有确实值。

df.isna().sum() 可以看到每列是否有缺失值。
