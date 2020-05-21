[toc]


# Vim YouCompleteMe安装

系统 Mac
Vim MacVim

## 安装C/C++ 补全

### 1. 使用 plug 安装，添加 

```
Plug 'https://github.com/ycm-core/YouCompleteMe'
```
之后 `:PlugInstall`，花费时间可能比较长。

### 2. 编译

进入 vim 安装 YouCompleteMe 的插件安装的目录中，我的目录是 `~/.vim/plugins/YouCompleteMe/`

```
$ cd ~/.vim/plugins/YouCompleteMe/
```

之后安装 

```
$ ./install.py --clang-completer
```

这里是编译 c/c++ 补全，其它语言可以使用别的编译选项。

### 3. 配置文件

根据 [ 3 ] 来进行配置

## 坑

解决方式来自于 [ 1 ] 

这里有一个坑。如果是用 Anaconda 环境中的 Python 运行上面的 `install.py` 文件，可能会无法补全。在进入 Vim 时会报错

```
The ycmd server SHUT DOWN (restart with :YcmRestartServer)
```

这时需要退出 Anaconda 环境，用 系统自带的 python 来进行安装。如果系统自带的 python 是 python2 的话，可以使用下面的命令来使用 `homebrew` 安装 python3 后再运行。

```
$ brew install python3
```


# References
1. ["The ycmd server SHUT DOWN (restart with :YcmRestartServer)" · Issue #914 · ycm-core/YouCompleteMe](https://github.com/ycm-core/YouCompleteMe/issues/914)
2. 官方：[ycm-core/YouCompleteMe: A code-completion engine for Vim](https://github.com/ycm-core/YouCompleteMe)
3. [VIM自动补全神器 --- YouCompleteMe 安装全教程 - 简书](https://www.jianshu.com/p/7c8d0510f1d6)
