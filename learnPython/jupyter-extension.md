[toc]

# Jupyter notebook 拓展

## 为Jupyter Notebook添加目录

具体可以看 [1]

## Hinterland 自动补全

Jupyter 默认是使用 tab 键才会出现自动补全菜单。而 Hinterland的 功能可以让你每敲完一个键，就出现下拉菜单，可以直接选中你需要的词汇。

## 主题设置

参考了 [3]

需要安装 `jupyterthemes`，注意要用 `--upgrade` 参数

```
pip install --upgrade jupyterthemes
```

然后就可以进行下面的设置
```
!jt -t oceans16 -f fira -fs 11 -cellw 90% -ofs 11 -dfs 11 -T
```

之后重启 Jupyter notebook 之外才可以看到效果变化

![预览](https://gitee.com/EdwardElric_1683260718/picture_bed/raw/master/img/20200514192500.png)

## Execute time

这个插件可以在 cell 下方添加运行时间。

### 安装

在 Nbextension 界面中搜索，勾选即可。

![execute time](https://gitee.com/EdwardElric_1683260718/picture_bed/raw/master/img/20200514193245.png)

### 效果预览

![preview](https://gitee.com/EdwardElric_1683260718/picture_bed/raw/master/img/20200514193209.png)



# References

1. [为Jupyter Notebook添加目录 - 知乎](https://zhuanlan.zhihu.com/p/24029578?refer=learnMLb/jupyter_contrib_nbextensions)
2. [Jupyter Notebook 有哪些奇技淫巧？ - 知乎](https://www.zhihu.com/question/266988943)
3. [Jupyter notebook使用技巧与JupyterLab - 简书](https://www.jianshu.com/p/f21595816abf)
