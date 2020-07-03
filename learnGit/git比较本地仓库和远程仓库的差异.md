
[toc]

# git比较本地仓库和远程仓库的差异

1、更新本地的远程分支

```
git fetch origin
```

2、本地与远程的差集 :（显示远程有而本地没有的commit信息）

```
git log master..origin/master
```

3、统计文件的改动

```
# git diff <local branch> <remote>/<remote branch>
git diff --stat master origin/master
```

# References
1. [git比较本地仓库和远程仓库的差异_开发工具_yjl2055的博客-CSDN博客](https://blog.csdn.net/yjl2055/article/details/101096467)
