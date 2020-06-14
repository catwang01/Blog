[toc]

# pandas 数据类型

## .astype

```python
import pandas as pd
```

```python
df = pd.DataFrame({
    'col1': [1,2,3,4],
    'col2': [4,2,3,1],
    'col3': [3,1,4,2]
})
```

```python
# 单行数据进行转换
df['col3'] = df['col3'].astype(int)
```

```python
# 多列进行数据转换
df = df.astype({"col1": "int8", 'col2': float})
```

```python
## select_dtypes() 筛选特定数据的特征

df.select_dtypes(include=['int'])
df.select_dtypes(exclude=['int'])
df.select_dtypes(include=['number']) # 筛选所有数值类型特征
df.select_dtypes(include=['object']) # 筛选所有 object 类型的列
```
