[toc]


有两种使用情况

1. 想要将 index 当作一列，可以用 

```
df.reset_index()
```


2. 不想要原来的 index，想重新编号，可以用

```
df.reset_index(drop=True)
```