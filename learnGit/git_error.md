
[toc]

# Git 错误解决

##### 1. `fatal: Could not read from remote repository`

- 参考：[这篇文章](https://youcanping.cn/2017/12/20/ssh-Permission-denied/)

##### 2. `fatal: remote origin already exist`
- 报错, 说明本地库已经和远程库关联过了，可以删除这个关联

##### 3. `[rejected]        master -> master (non-fast-forward)`

1. method1

- 原因在于git仓库中已经有一部分代码，因此它不允许直接将代码覆盖上去，需要使用`git pull`。而当在`master branch`上使用`git pull`时，需要进行如下设置  [See more for details](https://blog.csdn.net/lujinjian605894472/article/details/8443403)

```
git config branch.master.remote origin
git config branch.master.merge refs/heads/master
```
2. method2

```
git pull origin master
```

##### 4. `git pull` 时出现 `fatal: refusing to merge unrelated histories`

- 原因是本地的仓库和远程仓库的名称不同，此时可以使用`--allow-unrelated-histories`。[For more details](https://blog.csdn.net/sela0708/article/details/71480076)

##### 5. 坑！执行`git commit`时报错`error: pathspec 'readme.md' did not match any file(s) known to git.`。

- `git commit` 在 windows下要使用双引号，使用单引号时可能会报错


##### 6. src refspec master does not match any.

这个是提交空目录导致的。




# References
[github上传时出现error: src refspec master does not match any解决办法 - 简书](https://www.jianshu.com/p/8d26730386f3)
