[toc]


# git clean 删除未跟踪文件


```
# 删除 untracked files
git clean -f
 
# 连 untracked 的目录也一起删掉
git clean -fd
 
# 连 gitignore 的untrack 文件/目录也一起删掉 （慎用，一般这个是用来删掉编译出来的 .o之类的文件用的）
git clean -xfd
 
# 在用上述 git clean 前，墙裂建议加上 -n 参数来先看看会删掉哪些文件，防止重要文件被误删
git clean -nxfd
git clean -nf
git clean -nfd
```

# References

1. [(1条消息)git删除未跟踪文件_可来堂-CSDN博客_git删除未跟踪文件](https://blog.csdn.net/uhippo/article/details/46365737)
