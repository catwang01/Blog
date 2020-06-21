[toc]

# Python pip 源

## 常用的源

- 豆瓣(douban) http://pypi.douban.com/simple/ 
- 阿里云 http://mirrors.aliyun.com/pypi/simple/ 
- 中国科技大学 https://pypi.mirrors.ustc.edu.cn/simple/ 
- 清华大学 https://pypi.tuna.tsinghua.edu.cn/simple/ 
- 中国科学技术大学 http://pypi.mirrors.ustc.edu.cn/simple/

## 使用豆瓣源下载

```
pip3 install -i https://pypi.doubanio.com/simple/ numpy
```

## 设置豆瓣源

在 `~/.pip/pip.conf` 中（可能没有这个目录和文件，没事，直接创建一个就好）添加下面的内容

```
[global]
index-url = http://pypi.douban.com/simple/ 
```

# References

1. [(5条消息)pip国内源设置方法_你写代码的样子像极了CXK-CSDN博客_pip设置国内源](https://blog.csdn.net/weixin_41712059/article/details/86704492)