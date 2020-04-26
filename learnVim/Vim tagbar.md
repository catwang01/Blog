[toc]

# Vim Tagbar安装与 Markdown

系统是 Mac Os。
Vim 使用的是 MacVim

## 安装

在 `.vimrc` 中添加下面的内容
```
Plug 'majutsushi/tagbar'
``` 

安装之后使用 `:Tagbar` 结果发现有报错信息

```
Tagbar: Ctags doesn't seem to be Exuberant Ctags!
BSD ctags will NOT WORK. Please download Exuberant Ctags from ctags.sourceforge.net and install it in a directory in your $PATH or set g:tagbar_ctags_bin.
Executed command: "'ctags' --version"
Command output:
/Library/Developer/CommandLineTools/usr/bin/ctags: illegal option -- -
usage: ctags [-BFadtuwvx] [-f tagsfile] file ...
Exit code: 1 
```

说明 Mac 上面自带的 ctags 不支持。

### 安装 ctags

使用 `brew install ctags` 安装 `ctags`

安装好之后，使用下面的命令，查看 ctags 下载到哪个目录下了

```
$ brew list ctags
/usr/local/Cellar/ctags/5.8_1/bin/ctags
/usr/local/Cellar/ctags/5.8_1/include/readtags.h
/usr/local/Cellar/ctags/5.8_1/lib/readtags.o
/usr/local/Cellar/ctags/5.8_1/share/man/man1/ctags.1
```

可以看到 `ctags` 的安装路径为`/usr/local/Cellar/ctags/5.8_1/bin/ctags` 

因此需要在 vim 中设置ctags 的目录为上面的这个目录，在   `.vimrc` 中添加

```
let g:tagbar_ctags_bin = "/usr/local/Cellar/ctags/5.8_1/bin/ctags"
```

这样就可以使用 `ctags` 了!

## 一些配置

```
let g:tagbar_left = 1 " 设置在左边打开，和nerdtree一起使用时最好不使用这个设置。因为nerdtree一般会在左边
let g:tagbar_width = 30
```

### 自动打开

详细信息查看
```
:h tagbar-autoopen
```

下面设置自动打开c、c++、python 、markdown 的 tag

```
autocmd FileType c,cpp,py,markdown nested :TagbarOpe
```

### 跳转

在使用tagbar时，一般会多个文件同时打开。如果要直接从一个窗口跳转到其对应的 tagbar 的 window 中，可以添加下面的配置。

```
nnoremap tag :TagbarOpen fj<CR>
```

之后使用在 normal 模型中使用 tag 命令就可以直接跳转到 tagbar 的窗口中了。

## 添加Mardown支持

貌似有好几种方式来添加 Markdown支持。这里使用一种只依赖于 `ctags` 的。还有一种是要下载一个 markdown_2py.py文件的。那个尝试了一下没有成功。

1. 添加 `~/.ctags` 文件，并在其中添加下面的内容


```
--langdef=markdown
--langmap=markdown:.md
--regex-markdown=/^#{1}[ \t]*([^#]+.*)/. \1/h,headings/
--regex-markdown=/^#{2}[ \t]*([^#]+.*)/.   \1/h,headings/
--regex-markdown=/^#{3}[ \t]*([^#]+.*)/.     \1/h,headings/
--regex-markdown=/^#{4}[ \t]*([^#]+.*)/.       \1/h,headings/
--regex-markdown=/^#{5}[ \t]*([^#]+.*)/.         \1/h,headings/
--regex-markdown=/^#{6}[ \t]*([^#]+.*)/.           \1/h,headings/
```

2. 再在 `.vimrc`  中添加下面的内容即可

```
let g:tagbar_type_markdown = {
	\ 'ctagstype' : 'markdown',
	\ 'kinds' : [
		\ 'h:headings',
	\ ]
\ }
```

最后的效果

![picture here](https://gitee.com/EdwardElric_1683260718/picture_bed/raw/master/img/20200425192225.png)

# References
1. [让tagbar支持markdown | 净土](http://howiefh.github.io/2013/05/17/make-tagbar-support-markdown/)
2. [在 Vim 里为 Markdown 文档展示导航窗格 — 码志](https://mazhuang.org/2016/08/03/add-outline-for-markdown-in-vim/)
