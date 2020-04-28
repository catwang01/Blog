[toc]

# ML 学习笔记 8 -- 各种优化器的比较

## 标准的 Gradient Descent

$$
\theta \leftarrow \theta - \eta \frac{1}{N}\sum_{i=1}^{N} \nabla L(y_i, \hat{y}_i; \theta)
$$ 

需要将所有的样本处的梯度都累加起来，计算速度会比较慢

### SGD

不是使用全部的样本，而是只随机抽取一个样本来更新梯度。可以减少计算量，加快更新速度。

$$
\theta \leftarrow \theta - \eta \nabla L(y_i, \hat{y}_i; \theta)
$$ 

### Mini-Batch Gradient Descent

是上面两个方法的折中。取一个Batch来更新梯度，然后只累加 Batch 中的样本梯度。

当 Mini-Batch 只取一个样本时，就是 SGD；当 Mini-Batch 取所有样本时，就是标准的 Gradient Descent


**提示**：为了公式简单，之后的优化算法中，我们使用 $g(\theta)$  来代替梯度。

$g(\theta)$  的不同取值代表了不同的版本。如
- $g(\theta) = \frac{1}{N} \sum_{i=1}^{N} \nabla L(y_i, \hat{y}_i; \theta)$ 表示的是标准Gradient Descent版本；
- $g(\theta) = \nabla L(y_i, \hat{y}_i; \theta)$  表示 SGD版本等

## 动量优化

Gradient Descent 优化的一个方向是动量优化。有 Momentum 和 Nestrove Accelarated Gradient

### Momentum


在更新时不仅仅考虑本次更新方向，还考虑之前的更新方向。

$$
\begin{aligned}
& v \leftarrow  - \eta g(\theta) + \alpha v  \\
& \theta \leftarrow \theta + v
\end{aligned}
$$ 

其中是$v$ 表示之前的速度，初始化为 0。

![盗一张李宏毅的ppt](https://gitee.com/EdwardElric_1683260718/picture_bed/raw/master/img/20200428120654.png)

### NAG

更新速度的时间不仅考虑过去，还考虑未来

$$
\begin{aligned}
    & v \leftarrow \alpha v + \eta g(\theta + \alpha v) \\
    & \theta \leftarrow  \theta + v
\end{aligned}
$$ 

可以看到根据未来进行的一个校正。

## 自适应学习

对Gradient Descent进行优化的另一个方向是调整学习率的角度。主要的方法有 Adagrad、RMSprop

### Adagrad

Adagrad 是思路是对学习率进行一个加权。权重是累计的梯度平方和

$$
\begin{aligned}
    & h \leftarrow h + g^2 \\
    & \theta \leftarrow \theta - \eta \frac{1}{\sqrt{h + \epsilon} }g
\end{aligned}
$$ 

### RMSprop

RMSprop 对 Adagrad 进行了一个小小的改变。将梯度平方和的累加变成了梯度平方和的滑动平均。

Adagrad 会一直记得之前的信息，可能会导致到后面学习率太小，导致欠拟合。而 RMSprop 会逐渐忘记之前的信息。

$$
\begin{aligned}
    & h \leftarrow \alpha h + (1 - \alpha)g^2 \\
    & \theta \leftarrow \theta - \eta \frac{1}{\sqrt{h + \epsilon} }g
\end{aligned}
$$ 

![花书 rmsprop](https://gitee.com/EdwardElric_1683260718/picture_bed/raw/master/img/20200428132944.png)

## 集大成者 Adam

Adam 相当于将上面和两个方向的优化结合到了一起，并做出了一个修改。既考虑了动量的方向，又调整了学习率。


$$
\begin{aligned}
    & s \leftarrow \alpha s + (1-\alpha ) g \\
    & r \leftarrow \beta r + (1- \beta) g^2 \\
    & \hat{s} \leftarrow  \frac{s}{ 1 - \alpha^t} \\
    & \hat{r} \leftarrow  \frac{r}{ 1 - \beta^t} \\
    & \theta \leftarrow \theta - \eta \frac{1}{\sqrt{r + \epsilon} }  s
\end{aligned}
$$ 
 ![花书 Adam](https://gitee.com/EdwardElric_1683260718/picture_bed/raw/master/img/20200428134119.png)

# References

1. 花书
2. [An overview of gradient descent optimization algorithms](https://ruder.io/optimizing-gradient-descent/index.html)
3. [机器学习：各种优化器Optimizer的总结与比较_人工智能_SanFancsgo的博客-CSDN博客](https://blog.csdn.net/weixin_40170902/article/details/80092628)

