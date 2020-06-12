[toc]

# Matplotlib 自动关闭显示图像

希望实现的效果是显示一段时间后自动关闭。

```
plt.show()
```

不能做到这一点。可以使用下面的代码

```
plt.ion()


# plot some figures

plt.pause(0.1)
plt.close()
```

# References
1. [Python库matplotlib显示图形一定时间后自动关闭_Greathastemakesgreatwaste-CSDN博客](https://blog.csdn.net/xiaodongxiexie/article/details/78195860)