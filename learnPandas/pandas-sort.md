# Pandas Sort

```python
import pandas as pd
```

```python
dfdata = {
    'Score':[98,76,84,70,93,83],
    'Subject':['Literature','History','Enlish','Maths','Physics','Chemics'],
     'Name':['Zhang San','Li Si','Wang Laowu','Zhao Liu','Qian Qi','Sun Ba'],
}
scoresheet = pd.DataFrame(dfdata, index=['No2', 'No3', 'No1', 'No6', 'No5', 'No4'])
scoresheet
```

```python
scoresheet.sort_index() # 对行 index 排序
```

```python
scoresheet.sort_index(axis=1, ascending=False) # 对列 index 排序，即对 columns 排序
```

对 index 的情况不多，更多的是需要对 values 进行排序

```python
scoresheet.sort_values(by='Score')
```

```python
rrank = pd.Series([10,12,9,9,14,4,2,4,9,1])
rrank
```

```python
rrank.rank() # 求 rank
```

```python
rrank.rank(ascending=False) # 指定值越大的rank小
```
