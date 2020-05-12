[toc]

# Git使用

## 本地仓库

### 创建版本库(repository)

```
mkdir myrepository
cd myrepository
git init # 将本地目录变为可以管理的仓库
```

使用 `git init` 命令后目录下面会产生 `.git` 目录。

### 添加到仓库

```
git add readme.txt
git commit -m "wrote a readme file"

git add file1.txt
git add file2.txt
git add file3.txt
git commit -m "add 3 files"

# 添加所有文件
git add -A 
# 也可以用
git add .

# git add 一个文件夹，文件夹中的文件也会被 git add
git add fold

git commit -m "add 1 folder"
```

### 查看信息 

```
git status 查看工作区状态 
```

git status 的内容如下

![git status](https://gitee.com/EdwardElric_1683260718/picture_bed/raw/master/img/20200512180952.png)

#### git log 查看历史记录  

```
$ git log
commit d45182e78bd8162dea4c70b4ef2349f4117e5fd5 (HEAD -> master)
Author: ed <ed@eds-MacBook-Pro.local>
Date:   Mon Jan 20 14:50:58 2020 +0800

    add distributed

commit fd6c71e4d8255d369e7d335af32b5626b1fb17b5
Author: ed <ed@eds-MacBook-Pro.local>
Date:   Mon Jan 20 14:48:58 2020 +0800

    add readme
```

减少输出信息：

```
git log --pretty=oneline
```

结果

```
$ git log --pretty=oneline
d45182e78bd8162dea4c70b4ef2349f4117e5fd5 (HEAD -> master) add distributed
fd6c71e4d8255d369e7d335af32b5626b1fb17b5 add readme
```

注意：`git log`  查看的是 `commit`  的记录

### 版本回退 

 ![版本回退](https://gitee.com/EdwardElric_1683260718/picture_bed/raw/master/img/20200505110011.png)

#### git reset 版本回退

```
git reset --hard HEAD^ # 回退到上一个版本  
git reset --hard 388940 # 388940 是commit id下面的命令来查看
```
hard 参数是有些可怕的！慎重使用！

![版本ret回退 ](https://gitee.com/EdwardElric_1683260718/picture_bed/raw/master/img/20200505105929.png)

#### git reflog 查看commit id  

```
$ git reflog
fd6c71e (HEAD -> master) HEAD@{0}: reset: moving to HEAD^
d45182e HEAD@{1}: commit: add distributed
fd6c71e (HEAD -> master) HEAD@{2}: commit (initial): add readme
```

### 工作区和暂存区

工作区就是电脑上的目录
.git 目录就是 git的版本库了，其中又有两个一个是暂存区，一个是分支。

几个命令的作用：
1. git add 是将工作区的内容添加到暂存区中
2. git commit 是将暂存区中的内容添加到分支上。

![picgo](https://gitee.com/EdwardElric_1683260718/picture_bed/raw/master/img/20200505103420.png)

### 撤销修改


```
# 撤销所有修改
git checkout -- .
```

有三种场景

![picgo](https://gitee.com/EdwardElric_1683260718/picture_bed/raw/master/img/20200505103613.png)

### 删除文件

```
git add test.txt  
git commit -m 'add test.txt'  

rm test.txt # 从文件中删除，此时文件删除中，可是版本库中的test.txt还没有删除  
git rm test.txt # 从版本库中删除  
# 删除也需要提交
git commit -m "delete test"

git checkout --test.txt # 恢复删除  
```

如果只想从版本库中删除，而不想删除本地，可以使用

```
git rm --cached test.txt
# 删除也需要提交
git commit -m "delete test"
```

## 远程仓库

### 使用远程仓库

#### 创建远程仓库

#### 添加ssh连接

- 要使用Git连接到远程仓库，需要生成本地的公钥并添加到远程仓库的公钥列表中。

1. 运行下列命令可以在home目录下生成了.ssh目录，其中有`id_rsa`（私钥）和`id_rsa.pub`（公钥）

``` 
ssh-keygen -t rsa
```

2. 登陆 `GitHub`，打开`Accout settings`，`SSH Keys`, 点击`Add SSH Key`, 将`ir_rsa.pub`中的内容粘贴到Key中


![375d381ace031f3179cc20c64ce7f003.png](evernotecid://7E3AE0DC-DC71-4DDC-9CC8-0C832D6C11C2/appyinxiangcom/22483756/ENResource/p10519)


#### 将本地仓库和远程仓库关联

- 首先需要按照之前的步骤，建立一个本地仓库和一个远程仓库。

```
git remote add origin git@github.com:EdwardElric01/Notes   
```

- 添加后，远程库的名字就是`origin`，这是Git默认的叫法，也可以改成别的，但是`origin`这个名字一看就知道是远程库。

```
git push -u origin master
```

- 由于远程库是空的，我们第一次推送`master`分支时，加上了`-u`参数，Git不但会把本地的`master`分支内容推送的远程新的`master`分支，还会把本地的`master`分支和远程的`master`分支关联起来，在以后的推送或者拉取时就可以简化命令

- 之后push时只需要写

```
git push origin master
```

#### 查看远程仓库和分支

- 查看本地仓库关联的远程仓库
```
$ git remote show
origin
```

- 进一步查看远程仓库的信息

```
$ git remote show origin
* remote origin
  Fetch URL: git@github.com:EdwardElric01/learn_tensorflow
  Push  URL: git@github.com:EdwardElric01/learn_tensorflow
  HEAD branch: master
  Remote branch:
    master tracked
  Local ref configured for 'git push':
    master pushes to master (local out of date)
```

#### 删除p关联/重新关联

- 已经关联过了，想要重新删除关联再关联一次

```
git remote rm origin
```

### 使用分支

| command   | description    |
| --- | --- |
| git branch   | 查看分支 |
| git branch name   | 创建分支 |
| git checkout name   | 切换分支 |
| git checkout -b name   | 创建+切换分支 |
| git merge name   | 合并某分支到当前分支 |
| git branch -d name   | 删除分支 |

#### 创建分支


![56b37ea75b7c6b42fde2d0d01d98043b.png](evernotecid://7E3AE0DC-DC71-4DDC-9CC8-0C832D6C11C2/appyinxiangcom/22483756/ENResource/p10522)

1. 创建 dev 分支并切换到 dev 分支 

```
$ git checkout -b dev
Switched to a new branch 'dev'
```

![f020d0c3a0ae069e01380bf1975eedf2.png](evernotecid://7E3AE0DC-DC71-4DDC-9CC8-0C832D6C11C2/appyinxiangcom/22483756/ENResource/p10523)

`git branch` 查看当前分支

```
$ git branch
* dev
  master
```

2. 对 `readme.md` 文件进行修改并提交

```
$ git add .
$ git commit -m "modify by dev"
```

修改后的指针是这个样子的

![5c80b40b88b266a25ce31131da30c95a.png](evernotecid://7E3AE0DC-DC71-4DDC-9CC8-0C832D6C11C2/appyinxiangcom/22483756/ENResource/p10524)

3. 切换回master分支

```
$ git checkout master
Switched to branch 'master'
```

由于没有将修改合并到master分支，因此是这个样子的

![3e1d2a7b7724db2af5d112ee8890bec4.png](evernotecid://7E3AE0DC-DC71-4DDC-9CC8-0C832D6C11C2/appyinxiangcom/22483756/ENResource/p10526)

4. 合并分支到 master 上

```
$ git merge dev
Updating d45182e..f0effe1
Fast-forward
 readme.md | 1 +
 1 file changed, 1 insertion(+)
```

![08320202fad8ed1102d893a77bec10ad.png](evernotecid://7E3AE0DC-DC71-4DDC-9CC8-0C832D6C11C2/appyinxiangcom/22483756/ENResource/p10525)

5. 删除dev分支

```
$ git branch -d dev
Deleted branch dev (was f0effe1).
```
![4d6f59081a0698e3f2fad0be03c4ee61.png](evernotecid://7E3AE0DC-DC71-4DDC-9CC8-0C832D6C11C2/appyinxiangcom/22483756/ENResource/p10527)

查看一下，当前的分支在 master 上

```
$ git branch
* master∆
```

### 使用Github

#### git clone 和 fork 

git clone 是直接将仓库保存到本机上，clone 下来的仓库如果不是自己的远程仓库中的代码的话是不能 pull 和 push的

fork 是在github页面点击fork

![0ad22b4397ff1babc027261571aead72.png](evernotecid://7E3AE0DC-DC71-4DDC-9CC8-0C832D6C11C2/appyinxiangcom/22483756/ENResource/p10529)

之后就会将别人的仓库复制在自己的远程仓库中。

![2697b21619540888e29f3bb339dd7e6c.png](evernotecid://7E3AE0DC-DC71-4DDC-9CC8-0C832D6C11C2/appyinxiangcom/22483756/ENResource/p10528)

这时可以从自己的远程仓库 git clone 下来就可以在自己的远程仓库中 pull 和 push 了！


# References
- [代码管理| 本地Git仓库和远程仓库的创建及关联 - 云+社区 - 腾讯云](https://cloud.tencent.com/developer/article/1336316)
- [git clone和fork的区别_ghv587的博客-CSDN博客](https://blog.csdn.net/ghv587/article/details/51777174)

