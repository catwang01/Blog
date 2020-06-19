[toc]

# Pandas read_csv 分块读取

当 csv 文件比较大的时候，无法直接读入内存，可以使用 read_csv 来分块读取，处理后再写入文件中

## 方法一： read_csv 中设置 chunk_size

```python
import pandas as pd

input_path = 'unprocessed.csv'
output_path = 'processed.csv'
reader = pd.read_csv(input_path, chunksize=1000)
reader.get_chunk() # 返回一个 chuck，如果没有 chunk，引发 StopIteration 异常
```

## 方法二： get_chunk 中设置 chunksize

```python
reader = pd.read_csv(input_path, iterator=True) # 注意和上面的不同
chunksize = 1000
reader.get_chunk(chunksize=chunksize)
```

## 完整的 demo

```python
import pandas as pd

input_path = 'unprocessed.csv'
output_path = 'processed.csv'
reader = pd.read_csv(input_path, chunksize=1000)

i = 0
while True:
    try:
        chunk = reader.get_chunk()
    except StopIteration:
        break
    else:
        pass # process chunk here
    if i == 0:
        new_chunk.to_csv(output_path) # mode='a' 表示 append 追加
    else:
        new_chunk.to_csv(output_path, mode='a')
```
