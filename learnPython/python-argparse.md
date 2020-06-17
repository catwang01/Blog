[toc]

# Python argparse


## 基本使用

```
import argparse
parser = argparse.ArgumentParser()

parser.add_argument('--mode', type=str, default='srgan', help='srgan, evaluate')

args = parser.parse_args()
print(args.mode)
```

## 使用 bool 变量

argparse 不支持直接使用 bool 变量，假如有文件 `python-argparse.py` 中的内容如下

```
import argparse

parser = argparse.ArgumentParser()
parser.add_argument("--flag", type=bool, default=True, help="flag")
args = parser.parse_args()
print(args.flag)
```

但是使用下面的两个命令，输出均为 `True`

```
$ python python-argparse.py --flag True
True
$ python python-argparse.py --flag False
True
``` 

因为 argparse 不支持直接使用 bool 变量。

有下面几种方法可以解决

### 1. 使用 add_mutually_exclusive_group

```
import argparse

parser = argparse.ArgumentParser()

flag_parser = parser.add_mutually_exclusive_group(required=False)
flag_parser.add_argument('--true-flag', dest='flag', action='store_true')
flag_parser.add_argument('--false-flag', dest='flag', action='store_false')
parser.set_defaults(flag=True)

args = parser.parse_args()
print(args.flag)
```` 

结果

```
$ python python-argparse.py --true-flag
True
$ python python-argparse.py --false-flag
False
```

### 2. 使用一个函数进行类型转换

```
import argparse

parser = argparse.ArgumentParser()

def str2bool(v):
    if v.lower() in ('yes', 'true', 't', 'y', '1'):
        return True
    elif v.lower() in ('no', 'false', 'f', 'n', '0'):
        return False
    else:
        raise argparse.ArgumentTypeError('Unsupported value encountered.')

parser.add_argument(
    '--flag',
    type=str2bool,
    nargs='?',
    const=True,
    help='Turn on or turn off flag'
)


args = parser.parse_args()
print(args.flag)
```


```
$ python python-argparse.py --flag True
True
$ python python-argparse.py --flag False
False
```


# References
1. [(1条消息)使用Python中的argparse从命令行接收boolean类型的参数_正西风落叶下长安-CSDN博客_python args bool](https://blog.csdn.net/yaokai_assultmaster/article/details/77928629)
