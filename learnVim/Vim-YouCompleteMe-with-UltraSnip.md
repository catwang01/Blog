[toc]

# YCM和Ultisnips按键冲突解决方案（只使用TAB键，无错误）

# Preface

YCM(Youcompleteme)和Ultisnips两个都是很神奇的插件，但是更加神奇的事情发生了，他们的按键产生冲突。有很多的人都采取了替换别的按键的方法～但是作为一个完美主义者，而且为了减轻记忆的压力，算了吧～直接就不改按键了。

---

# 1. 原理

有两篇文章可以看一下，不过是英文的：
- [How to Make YouCompleteMe Compatible With UltiSnips](http://0x3f.org/blog/make-youcompleteme-ultisnips-compatible/?utm_source=tuicool&utm_medium=referral "How to Make YouCompleteMe Compatible With UltiSnips")
- [Github Issue-36](https://github.com/Valloric/YouCompleteMe/issues/36 "Github Issue-36")
- [YCM–AND–Yltisnips—Stackoverflow](http://stackoverflow.com/questions/14896327/ultisnips-and-youcompleteme)

主要是Ultisnips的调用等级比较高，如果有snippets的时候就会调用Ultisnips，如果没有snippets的时候就会调用YCM的自动补全功能。这样就可以完美的结合了。不过呢，在别人提供的方案里面（本例中），是将Utlisnips的内容放在YCM的补全列表里面，然后再将snippets放入其中。

---

# 2. 具体的修改方案

因为github上的issue上面的内容比较杂，因此整理出来：（本方案纯粹采集于github issue上的comment里的，亲自测试过没有问题）

1. Install YCM

2. Install UltiSnips

3. 添加功能函数到`.vimrc` (from @JazzCore)

```vim
function! g:UltiSnips_Complete()
  call UltiSnips#ExpandSnippet()
  if g:ulti_expand_res == 0
    if pumvisible()
      return "<C-n>"
    else
      call UltiSnips#JumpForwards()
      if g:ulti_jump_forwards_res == 0
        return "<TAB>"
      endif
    endif
  endif
  return ""
endfunction

function! g:UltiSnips_Reverse()
  call UltiSnips#JumpBackwards()
  if g:ulti_jump_backwards_res == 0
    return "<C-P>"
  endif

  return ""
endfunction

if !exists("g:UltiSnipsJumpForwardTrigger")
  let g:UltiSnipsJumpForwardTrigger = "<tab>"
endif
if !exists("g:UltiSnipsJumpBackwardTrigger")
  let g:UltiSnipsJumpBackwardTrigger="<s-tab>"
endif

```

4. 为上面的函数创建一个自动BufEnter

```vim
au InsertEnter * exec "inoremap <silent> " . g:UltiSnipsExpandTrigger     . " <C-R>=g:UltiSnips_Complete()<cr>"
au InsertEnter * exec "inoremap <silent> " .     g:UltiSnipsJumpBackwardTrigger . " <C-R>=g:UltiSnips_Reverse()<cr>"
```

5. 使用

- 如果有snips，直接按tab键就可以完成添加
- tab键往下走，shfit+tab键往上走

此方案基本无bug，解决了所有的出现的问题！
唯一的不足，唯一的！就是在有的时候补全会闪一下！日后修复这个问题。

# References
1. [YCM和Ultisnips按键冲突解决方案（只使用TAB键，无错误）_开发工具_NahNahNah!!-CSDN博客](https://blog.csdn.net/qq_20336817/article/details/51115411)
