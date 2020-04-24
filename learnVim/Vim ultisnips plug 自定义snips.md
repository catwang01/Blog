[toc]

# Vim ultisnips plug 自定义snips

## common

### 1. 自定义括号补全

参考了 [1]
```
snippet ( "if (...)" iA
(${1:${VISUAL: }})$0
endsnippet

snippet { "if [...)" iA
{${1:${VISUAL: }}}$0
endsnippet
```

## Markdown

### 1. 自定义代码块

```
snippet ` "Codeblock" bA 
\`\`\`
${VISUAL}
\`\`\`
$0
endsnippet
```

# References
1. [vim为markdown文件写snippets - 简书](https://www.jianshu.com/p/b07867e80296)
