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

```
df1.rename(columns={'c':'D'},inplace=True)
print('修改一个列名\nmethod2_inplace:\n',df1)
```

## groupby

### count

```
beh.groupby(['id', 'page_no']).count()
Out[6]:
                 page_tm
id      page_no
U4B9037 AAO           18
        CQA           41
        FTR            7
        MSG           11
        SZA            8
...                  ...
UD340F0 MSG            1
UD34FCE AAO            8
        CQA           11
        MSG            1
        SZA            5
[12486 rows x 1 columns]
```

### as_index=Fasle

```
beh.groupby(['id', 'page_no'], as_index=False).count()
Out[7]: 
            id page_no  page_tm
0      U4B9037     AAO       18
1      U4B9037     CQA       41
2      U4B9037     FTR        7
3      U4B9037     MSG       11
4      U4B9037     SZA        8
...        ...     ...      ...
12481  UD340F0     MSG        1
12482  UD34FCE     AAO        8
12483  UD34FCE     CQA       11
12484  UD34FCE     MSG        1
12485  UD34FCE     SZA        5
[12486 rows x 3 columns]

```

## duplicate

```
df.duplicated()
df.drop_duplicated()
```

