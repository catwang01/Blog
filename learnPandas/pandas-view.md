[toc]

# Pandas 可视化探索

## 一个连续变量


## 两个连续变量之间的关系

### 散点图

#### df.plot

```
iris.plot(kind="scatter", x="SepalLengthCm", y="SepalWidthCm")
```

#### plt.scatter

```
plt.scatter(x="SepalLengthCm", y="SepalWidthCm", data=iris)
```

![scatter](https://gitee.com/EdwardElric_1683260718/picture_bed/raw/master/img/20200507105533.png)

### 散点图 + histogram

在散点图的基础上添加了直方图

#### sns.jointpot

```
sns.jointplot(x="SepalLengthCm", y="SepalWidthCm", data=iris, size=5)
```

![jointplot](https://gitee.com/EdwardElric_1683260718/picture_bed/raw/master/img/20200507105751.png)

## 两个连续变量 + 一个离散变量

在 plt.scatter 的基础上，添加一个离散变量，在图中将离散变量的值用不同的颜色标记出来

```
sns.FacetGrid(iris, hue="Species", size=5) \
   .map(plt.scatter, "SepalLengthCm", "SepalWidthCm") \
   .add_legend()
```
![facetgrid](https://gitee.com/EdwardElric_1683260718/picture_bed/raw/master/img/20200507110028.png)

## 一个连续变量一个离散变量

### 密度图

![](https://gitee.com/EdwardElric_1683260718/picture_bed/raw/master/img/20200507121640.png)

### boxplot

这个用来是探究一个离散变量和一个连续变量之间的关系。

```
sns.boxplot(x="Species", y="PetalLengthCm", data=iris)
plt.show()
```
![boxplot](https://gitee.com/EdwardElric_1683260718/picture_bed/raw/master/img/20200507104831.png)

### boxplot + stripplot

```
ax = sns.boxplot(x="Species", y="PetalLengthCm", data=iris)
ax = sns.stripplot(x="Species", y="PetalLengthCm", data=iris, jitter=True, edgecolor="gray")
```


### violinplot

A violin plot combines the benefits of the previous two plots and simplifies them
 Denser regions of the data are fatter, and sparser thiner in a violin plot

```
sns.violinplot(x="Species", y="PetalLengthCm", data=iris)
plt.show())
```
![violinplot](https://gitee.com/EdwardElric_1683260718/picture_bed/raw/master/img/20200507105202.png)   

# References
1. [Python Data Visualizations | Kaggle](https://www.kaggle.com/benhamner/python-data-visualizations)
