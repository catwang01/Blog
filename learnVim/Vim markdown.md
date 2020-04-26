[toc]

# Vim markdown

## 表格相关

```
:TableFormat 
```

有这个实际上不需要 vim-table-mode 插件了

## conceal

使用下面的命令查看帮助

```
:h vim-markdown-syntax-concealing
```

这个用于浏览的时候比较好。不适合用于编辑

常用的配置

```
set conceallevel=2
let g:vim_markdown_conceal_code_blocks = 0
```
