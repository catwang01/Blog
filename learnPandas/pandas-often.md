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

# df2 修改 df1 也会修改
df1 = pd.DataFrame({"col1": [1,2,3]})
df2 = df1
df2.iloc[0, 0] = 2
df2
df1

## 修改列名

df1.rename(columns={'c':'D'},inplace=True)
print('修改一个列名\nmethod2_inplace:\n',df1)
