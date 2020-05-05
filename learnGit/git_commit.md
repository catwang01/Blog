[toc]

# Todo - 2020-05-05 11:08 -- by  ed  这个只是copy 人家的，还没有自己总结呢

# git commit

## commit

Git有三大区（工作区、暂存区、版本库）以及几个状态（untracked、unstaged、uncommited）

Git 保存的不是文件的变化或者差异，而是一系列不同时刻的文件快照。

git reset命令是git中重置命令，即用来撤销某次提交(commit)。首先，我们得了解，git reset可以帮我们重置哪些内容：

- - 1、修改本地仓库中commit对象(快照)- - 

如下图：

![](https://upload-images.jianshu.io/upload_images/15449003-d8f7a6849d697eac.png?imageMogr2/auto-orient/strip|imageView2/2/w/711/format/webp)

此时本地仓库对应的是commit4，git reset 可以让本地仓库对应的指针变为commit3或是commit1等之前的版本，当然，也可以变为commit4之后的某个commit，如commit5。
- - Git 的分支，其实本质上仅仅是指向提交对象的可变指针。- - 
- - 备注- - ：当使用git reset命令时候，一般会修改本地仓库。

其常用格式如下：

- 用法一：git reset [-q] [<commit] [--] <paths...
- 用法二：git reset [--soft | --mixed | --hard | --merge | --keep ] [-q] [commit]

#### 二、参数

- - 参数说明- - (git log和git reflog可查看commitId，commitId是快照的唯一标识)

- --hard commitId 修改- - 本地仓库、暂存区、工作区- - 里面的数据为commitId对应快照的内数据

![](https://upload-images.jianshu.io/upload_images/15449003-b78252282c3cee25.png?imageMogr2/auto-orient/strip|imageView2/2/w/1200/format/webp)

- --mixed commitId 修改- - 本地仓库、暂存区- - 里面的数据为commitId对应快照里的数据，是git reset默认的参数，--mixed可缺省。 暂存区的数据会被快照中的数据覆盖

这种情况是工作区没有，但暂存区有，所以提示修改未在暂存区（D表示delete）

- --soft commitId 修改- - 本地仓库- - 里面的数据为commitId对应快照的数据。(仅改变指向快照的指针指向)

![](https://upload-images.jianshu.io/upload_images/15449003-3e830cb8f28d36b7.png?imageMogr2/auto-orient/strip|imageView2/2/w/1200/format/webp)

##### 当git reset 后面的commitId为当前提交的commitId时，即- - HEAD- - (可缺省)。那么：

- - 参数说明- - 

- --hard HEAD 修改- - 暂存区、工作区- - 里面的内容为当前快照里的内容。（这个很危险，曾经踩过坑，电脑的文件丢失了很多，也是导致我决心好好学一学git的原因，慎用）
- --mixed HEAD 修改- - 暂存区- - 里面的内容为当前快照里的内容，是git reset默认的参数，因此可缺省。
- --soft HEAD - - 本地仓库、暂存区、工作区- - 都不改变 |

我们需要注意，使用git reset重置一般是很危险的，会彻底地丢掉历史。因为如果没有记录下重置前的commitId，一般不容易找回，除非分析.git/logs里面的日志，故重置需慎重。- - 

- git diff- - 只对已被追踪的文件起作用，即已- - git add- - 过，在暂存区有的

- git commit -a -m- - 只对已被追踪的文件起作用，

# References
1. [git撤销提交(commit) - 简书](https://www.jianshu.com/p/b735f7accb20)
