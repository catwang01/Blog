[toc]

# Git 修改用户名和邮箱

## 用户名和邮箱地址的作用

用户名和邮箱地址是本地git客户端的一个变量

每次commit都会用用户名和邮箱记录, github的contributions统计就是按邮箱来统计的。

如果发现  git commit 没有被算到 contributions 中去，那就要检查用户名和邮箱是否是我们的帐号的用户名和和邮箱。

## 三个级别的设置

有三个级别的配置

### 系统级别的配置

配置文件位于 

```
/etc/gitconfig
```

系统级别的配置,适用于所有的用户和所有的库,

查看

```
$ git config --system user.name
$ git config --system user.email
```

修改

```
$ git config --system user.name "myname"
$ git config --system user.email myemail
```

### 用户级别的配置

```
~/.gitconfig
```

用户级别的配置,适用于当前登录的用户,可以使用 `$ git config --global` 来指定和修改

查看

```
$ git config --global user.name
$ git config --global user.email
```
修改

```
$ git config --global user.name "myname"
$ git config --global user.email myemail
```

### 库级别的配置

```
.git/config
```

库级别的配置,适用于某个具体的库,可以使用 `$ git config` 来指定和修改,存储在具体的库隐藏的.git文件夹下

```
$ git config user.name
$ git config user.email
```

```
$ git config --global user.name "username"
$ git config --global user.email "email"
```

系统级别的: Git会优先使用库级别的配置,再然后是global级别的配置,最后是system级别的配置.

# References
1. [Git配置用户名与邮箱 - gudi - 博客园](https://www.cnblogs.com/gudi/p/6597660.html)
