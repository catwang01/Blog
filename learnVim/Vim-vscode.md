[toc]

# Vscode vim

## 修改 leader 键

command + , 打开 setting 界面, 在搜索框中输入 vim:leader 就可以找到

![75a09c7bf508f34b6f27c573c7b32159.png](evernotecid://7E3AE0DC-DC71-4DDC-9CC8-0C832D6C11C2/appyinxiangcom/22483756/ENResource/p13908)

也可以在 setting.json 中添加

```
"vim.leader": ','
```

## vim-easymotion 

和 vim 中的 easymotion 插件类似

### 打开
command + , 打开 setting 界面，在搜索框中输入 vim:easymotion 就可以得到所有关于 vim-easymotion 的相关配置。

### 使用

和 vim 中的 easymotion 插件类似。主要用 <leader><leader>s + <char> 这个命令就可以了

## vim-surround

vim-surround 处理环绕文本操作，如引号 ” 括号（）方括号[] 花括号{} xml html标签等。

具体的使用说明可以查看 [ 1 ]
| 命令 | 说明 |
| --- | --- |
| `d s <existing char>` | 删除两边的指定字符 |
| `c s <existing char> <desired char>` | 修改两边的指定字符 |
| `y s <motion> <desired char>` | 修改两边字符 |
| `S <desired char>` | visual modes 选中指定字符中间的内容 |

例子:

*   `"test"` 输入 cs"'修改为 `'test'`
*   `"test"` 输入 ds" 修改为 `test`
*   `"test"` 输入 cs"<123> 修改为`<123>test</123>`
*   `test` 输入 ysaw) 修改为 `( test )`
* `test`  VISUAL 模式下选中 test，按下 `S`，再按下 `(` 修改为 `( test )`

## 注释

代码注释vsc使用了类似vim-commentary的操作。
使用方法:

*  `gc` - 打开或关闭注释. 输入 `gcc` 打开或关闭某一行代码注释， `gc2j` 打开或关闭两行代码注释。
*  `gC` - 块代码注释.输入 `gCi)` 注释 括号()中的代码。

##  其他功能

| 命令 | 功能 |
| -- | -- |
| gh  | 查看帮助文档和提示 |
| gd | 进入源文件 ctrl+O 回来 |
| gt | 切换到下一个界面 |
| gT | 切换到上一个界面 |

# References

1. [VSCode Vim进阶操作 - 简书](https://www.jianshu.com/p/cbfa86c8d8a5)
2. [vim插件——vim-surround_liao20081228的博客-CSDN博客](https://blog.csdn.net/liao20081228/article/details/80347684)
3. [《Vim实用技巧》读书笔记_WeiSenhui的博客-CSDN博客](https://blog.csdn.net/qq_43827595/article/details/106291578)