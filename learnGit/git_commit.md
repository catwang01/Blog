[toc]

# git commit后，如何撤销commit

修改了本地的代码，然后使用：

```
git add file
git commit -m '修改原因'
```
执行commit后，还没执行push时，想要撤销这次的commit，该怎么办？

## 解决方法

```
git reset --soft HEAD^
```

这样就成功撤销了commit，如果想要连着add也撤销的话，--soft改为--hard（删除工作空间的改动代码）。

- --soft
不删除工作空间的改动代码 ，撤销commit，不撤销git add file

- --hard
删除工作空间的改动代码，撤销commit且撤销add

另外一点，如果commit注释写错了，先要改一下注释，有其他方法也能实现，如：

```
git commit --amend
```

这时候会进入vim编辑器，修改完成你要的注释后保存即可。

# References
1. [git commit后，如何撤销commit - 简书](https://www.jianshu.com/p/a9f327da3562) 
