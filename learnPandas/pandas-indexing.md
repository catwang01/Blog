[toc]

# Pandas Indexing

```python
import pandas as pd
```

```python
dfdata = {'Name':['Zhang San','Li Si','Wang Laowu','Zhao Liu','Qian Qi','Sun Ba'],
        'Subject':['Literature','History','Enlish','Maths','Physics','Chemics'],
        'Score':[98,76,84,70,93,83]}
scoresheet = pd.DataFrame(dfdata, index=['No1', 'No2', 'No3', 'No4', 'No5', 'No6'])
scoresheet
```

```python
scoresheet['Subject'] # 提取 Subject 列
```

```python
scoresheet.Subject
```

```python
scoresheet[['Subject']] # 提取列(这样返回的是 DataFrame， scoressheet['Subject']) 返回的是 Series
```

```python
# 提取多列
scoresheet[['Name', 'Score']]
```

```python
# 切片提取的是行
scoresheet[:4]
```

```python
# 使用非整数切片时，包含末尾
# 注意提取的是行
scoresheet["No3":"No4"] 
```

```python
scoresheet.loc[["No1", "No3", "No6"]] # 提取行
```

```python
scoresheet.loc[:, ["Score", 'Name']] # 提取列
```

```python
scoresheet.loc[['No1', 'No3', 'No6'], ["Score", 'Name']] # 提取行列
```

.iloc 和 .loc 的用法相同。只不过是用下标来进行切片

```python
scoresheet.iloc[[0,2,5]]  # 第 1，3，6 行
```

```python
scoresheet.iloc[:, [1,2]] # 第 2，3 列
```

```python
scoresheet.iloc[[0,2,5], [1,2]] 
```
