[toc]

# python ctypes 数组的使用

## 一维数组

定义 5 个 int 元素的数组

```
c_list = (ctypes.c_int * 5)()
```

没有参数默认初始化为全0，可以初始化

```
# 部分初始化
c_list = (ctypes.c_int * 5)(1,2,3)
```

下面展示如何使用一个 list 来进行初始化

```
A = [1, 2, 3, 4, 5]
c_list = (ctypes.c_int * 5)(*A)
```

## 二维数组

定义 2 x 3 的 float 类型的二维数组

```
c_list = ((ctypes.c_int * 2) * 3)()
```

如何从上面定义的 c_list 中取出元素？ 直接将 c_list 当作 python 的 list 对象来使用就可以

```
c_list[0]   # 可以索引
c_list[1:3] # 可以切片
for x in c_list: # 可以迭代
    print(x)
```