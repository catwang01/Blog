[toc]

# Todo - 2020-05-05 11:08 -- by  ed  这个只是copy 人家的，还没有自己总结呢

# git reset

## reset 

Git有三大区（工作区、暂存区、版本库）以及几个状态（untracked、unstaged、uncommited）

Git 保存的不是文件的变化或者差异，而是一系列不同时刻的文件快照。

git reset命令是git中重置命令，即用来撤销某次提交(commit)。首先，我们得了解，git reset可以帮我们重置哪些内容：

- 用法一：git reset [-q] [<commit] [--] <paths...
- 用法二：git reset [--soft | --mixed | --hard | --merge | --keep ] [-q] [commit]

#### 二、参数

- --hard commitId 修改 **本地仓库、暂存区、工作区** 里面的数据为commitId对应快照的内数据，**这个很危险**
- --mixed commitId 修改**本地仓库、暂存区**里面的数据为commitId对应快照里的数据，是git reset默认的参数，--mixed可缺省。 暂存区的数据会被快照中的数据覆盖。
- --soft commitId 修改**本地仓库**里面的数据为commitId对应快照的数据。(仅改变指向快照的指针指向)

我们需要注意，使用git reset重置一般是很危险的，会彻底地丢掉历史。因为如果没有记录下重置前的commitId，一般不容易找回，除非分析.git/logs里面的日志，故重置需慎重。- - 

# References
1. [git撤销提交(commit) - 简书](https://www.jianshu.com/p/b735f7accb20)
