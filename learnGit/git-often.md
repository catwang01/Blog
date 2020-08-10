[toc]

# Git 常用

## git commit --amend

```
git commit --amend
```

追加提交，它可以在不增加一个新的commit-id的情况下将新修改的代码追加到前一次的commit-id中。还可以用来修改前一次 commit 的信息。

## Git 还原某个文件

如何用版本库中的文件替换工作区中的文件？

使用 git reset --hard 可以用版本库来替换工作区中内容。但是只能替换整个 commit，而不能替换一个文件。使用 `git checkout` 可以达到这个目的。


1. 查看某个文件相关的 commit-id

```
git log xxfile
```

这样可以找到要修改的文件对应的 commit-id

2. 
```
git checkout commit-id xxfile
```


# References

1. [版本控制 - git 如何还原某个文件 - SegmentFault 思否](https://segmentfault.com/q/1010000002464973)

