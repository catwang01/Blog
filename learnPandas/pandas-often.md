[toc]


.describe()

.unique()

.dtypes()
.drop()


## pd.merge

```
train1 = pd.merge(train, store, on='Store')
test1 = pd.merge(test, store, on='Store')
```

## Using series.replace() to encode features

```
features.extend(['StoreType', 'Assortment', 'StateHoliday'])
mappings = {'0':0, 'a':1, 'b':2, 'c':3, 'd':4}
data.StoreType.replace(mappings, inplace=True)
data.Assortment.replace(mappings, inplace=True)
data.StateHoliday.replace(mappings, inplace=True)
```

## .列名

```
df.Haha # 相当于 df['Haha]
```

df.value_count()

## series.value_count()

分类统计类别数
