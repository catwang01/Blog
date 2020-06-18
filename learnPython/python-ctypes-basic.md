[toc]

# Python ctypes 基本使用

## 编写 c/c++ 程序

先写一个简单的 hello world 程序，这里是用 cpp 来实现的

```cpp
#include <cstdio>

extern "C" {
    int printHello()
    {
printf("Hello world!\n");
        return 0;
    }
}
```

完成这个函数之后进行编译，

 ```
 g++ hello.cpp -O3 -shared -fPIC -o hello.so
 ```

 得到了
`hello.so` 文件，下面我们用 python 来调用这个文件中的函数

## 使用 python 调用

在同一目录下，创建 `test_hello.py` 文件，内容如下

```python

import ctypes

lib = ctypes.cdll.LoadLibrary('hello.so')
lib.printHello()
```


运行上面的 `test_hello.py` 脚本，可以看到输出结果

```
$ python test_hello.py 
Hello world!
```
