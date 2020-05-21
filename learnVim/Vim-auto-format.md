[toc]

# Vim Auto-format

这个插件是一个框架，可以配合其它格式化工具来对代码进行格式化。


## 安装

在 `~/.vimrc` 中添加

```
Plug 'Chiel92/vim-autoformat'
```

## 使用

```
:Autoformat
```

也可以指定在保存文件时进行自动格式化。在 `~/.vimrc` 中添加下面的内容

```
au BufWrite *:Autoformat
```

也可以只指定部分文件保存时自动格式化，如想要在 `.cpp` 文件保存时自动格式化

```
au BufWrite *.cpp :Autoformat
```

个人建议还是手动格式化比较好。

## 自定义 c++ 的格式化风格

### 使用 `clang-format` 格式化

可以使用 `clang-format` 对 c++ 代码进行格式化。

首先安装 `clang-format` 。笔者是用 mac 系统，所以使用 homebrew 来进行安装

```
brew install clang-format
```

`clang-format` 是一个格式化 c++ 代码的专门的工具。这里只是使用其命令而已。

在 `~/.vimrc` 中添加下面的内容

```
let g:formatdef_mycustom = '"clang-format -style=\"{BasedOnStyle: llvm, IntentWidth: 4, BreakBeforeBraces: Allman}\""' 
let g:formatters_cpp = ['mycustom']
```

其中第一句自定义了一个 formatter，名字叫 `mycustom` ；第二句指定这个 formatter 来格式化 c++ 代码。

因此可以根据 `clang-format` 的使用自定义自己的 format。这里是在 llvm 风格的基础上修改为 IntentWidth 和 BreakBeforeBraces 两个参数。这种用法是从 `clang-foramt --help` 中看到的。

```
-style=<string>           - Coding style, currently supports:
                               LLVM, Google, Chromium, Mozilla, WebKit.
                             Use -style=file to load style configuration from
                             .clang-format file located in one of the parent
                             directories of the source file (or current
                             directory for stdin).
                             Use -style="{key: value, ...}" to set specific
                             parameters, e.g.:
                               -style="{BasedOnStyle: llvm, IndentWidth: 8}"

```

注意，自定义的 clang 语句的最外层有一个 双引号。而上面的 clang 语句中本身就有一个双引号，因此需要使用反斜杠进行转义。

clang-format 的更多使用，可以查看 [ 1 ] [ 2 ]

### 使用 astyle 格式化

刚开始的时候使用的是 `clang-format`，之后发现没有 `astyle` 好用，就用了 astyle.

#### 安装 astyle (推荐)

mac 上直接使用 homebrew 安装即可

```
brew install astyle
```

安装之后在 `~/.vimrc` 中添加下面的内容。

```
let g:formatdef_mycustom = '"astyle --style=ansi"' 
let g:formatters_cpp = ['mycustom']
```

由于默认的 `ansi`  风格已经可以满足我的要求了，因此就没有继续设置。更多的风格，可以参考 [ 5 ]

# References

1. [Chiel92/vim-autoformat: Provide easy code formatting in Vim by integrating existing code formatters.](https://github.com/Chiel92/vim-autoformat)
2. [Clang-Format格式化选项介绍_c/c++_子丰的博客-CSDN博客](https://blog.csdn.net/softimite_zifeng/article/details/78357898)
3. clang-format 的官方文档 [Clang-Format Style Options — Clang 11 documentation](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)
4. 值得继续看：[Vim插件之vim-autoformat - 码农教程](http://www.manongjc.com/article/35909.html)
5. [Artistic Style](http://astyle.sourceforge.net/astyle.html#_indent-after-parens)
