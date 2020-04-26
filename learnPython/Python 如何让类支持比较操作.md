[toc]

# Python 如何让类支持比较操作

## 1. 重载`__lt__, __le__, __gt__, __ge__, __eq__, __ne__`，

但这样需要写的函数太多了

```
class Rectangle(object):
    def __init__(self, w, h):
        self.w = w
        self.h = h

    def area(self):
        return self.w * self.h

    def __lt__(self, obj)
        return self.area() < obj.area()
    ## ... 其它类似的比较操作符
```

## 2. 使用标准库中的`functools.total_ordering`

```
from functools import total_ordering

@total_ordering
class Rectangle(object):
    def __init__(self, w, h):
        self.w = w
        self.h = h
    def area(self):
        return self.w * self.h
    def __lt__(self, obj):
        return self.area() < obj.area()
    def __eq__(self, obj):
        return self.area() == obj.area()

R1 = Rectangle(1,2)
R2 = Rectangle(3,2)
R1 < R2
```

