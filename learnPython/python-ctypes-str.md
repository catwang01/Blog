[toc]

# Python ctypes 字符串使用

```python
import ctypes

s = (ctypes.c_char * 100)()
print(s) # c_char_Array_100 对象
```

初始化参数 （str 转化为 c_char_Array)

```python
s = (ctypes.c_char * 100)(*bytearray("hello world", encoding='utf8'))
print(s)
```

## c_char_Array 转化为 str

```python
bytearray(s).decode("utf8").strip('\x00')
```
