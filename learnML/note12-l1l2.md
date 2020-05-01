[toc]

# ML 学习笔记 L1 L2 正则化

假设无约束的损失函数为  $L_0$ 

L1 正则：

$$
L_{1}=L_{0}+\lambda \sum_{i=1}^{p}\left|w_{i}\right|
$$

L2 正则：

$$
L_{2}=L_{0}+\lambda \sum_{i=1}^{p} w_{i}^{2}
$$

## 为什么 L1 相比于 L2 容易获得稀疏解

### 梯度下降角度

L1 的权重更新公式：

$$
w_{i} \leftarrow w_{i}-\eta \frac{\partial L_{0}}{\partial w_{i}}-2 \eta \lambda \operatorname{sign}\left(w_{i}\right)
$$

L2 的权重更新公式：

$$
w_{i} \leftarrow w_{i}-\eta \frac{\partial L_{0}}{\partial w_{i}}-2 \eta \lambda w_{i}
$$

可以看到，在相同权重的情况下，L1更新幅度是固定的步长，与 $w_i$ 的正负有关，而和 $w_i$ 的大小无关。L2 更新幅度与 $w_i$ 有关。当 $w_i$ 大于 1 时，L2 的更新幅度比 L2 大，因此可以使 $w_i$ 迅速减少。而当 $w_i$ 小于1时，L2 的更新幅度小于 L1 的更新幅度。

因此，相比于 L1 的固定步长来说，L2 的步长更倾向于让大的 $w_i$ 变小，但是不倾向于将小的 $w_i$ 压缩到0；而 L1 可以将小的 $w_i$ 压缩到 0。

### 从Bayes的角度

L1 对应于 Laplace 分布

Laplace 分布有两个参数 $\mu$  和 b ， $Laplace(\mu, b)$ 的密度为

$$
f(x ; \mu, b)=\frac{1}{2 b} \exp \left(-\frac{|x-\mu|}{b}\right)
$$

当 $x \sim Laplace(0, b)$  (注意这里取 $\mu=0$ )，其概率密度为

$$
P(x)=\frac{1}{2} \exp \left(-\frac{|x|}{b}\right)
$$

后验概率为

$$
P(y | x) \propto P(x | y) P(x)
$$

取 −log 并省略常数，得到

$$
\begin{aligned}
L &=-\log P(x | y)-\log P(x) \\
&=-\log P(x | y)+\log 2+\frac{1}{b}|x|
\end{aligned}
$$

省略常数，令 $\frac{1}{b} = \lambda$ ，则有

$$
L=-\log P(x | y)+\lambda|x|
$$

L2 对应于 Guassian，其密度函数为

$$
f\left(x ; \mu, \sigma^{2}\right)=\frac{1}{\sqrt{2 \pi} \sigma} \exp \left(-\frac{(x-\mu)^{2}}{2 \sigma^{2}}\right)
$$

代入，化简，得到

$$
L=-\log P(x | y)+\lambda x^{2}
$$

结合 Laplace 分布 和 Guassian分布的图像可以看出，服从 Laplace 分布的随机变量更容易取到0。（因为在0处的密度要更高）

### 从优化角度

L1 正则：

$$
L 1=L_{0}+\lambda \sum_{i=1}^{p}\left|w_{i}\right|
$$

上面的式子可以转化下面的有约束优化问题：

$$
\begin{aligned}
&\min L_{0}\\
&\text {s.t} \quad \sum_{i=1}^{p}\left|w_{i}\right| \leq \eta
\end{aligned}
$$

L2 正则：

$$
L 2=L_{0}+\lambda \sum_{i=1}^{p} w_{i}^{2}
$$

可以转化为

$$
\begin{aligned}
&\min L_{0}\\
&\text {s.t} \quad \sum_{i=1}^{p} w_{i}^{2} \leq \eta
\end{aligned}
$$

取 $p=2$  表示有两个参数，再取 $L_0$ 为二次函数，其等高线为椭圆。

而 L1 正则对应的约束区域为 $|x_1| + |x_2| \le  \eta$  ，其形状为顶点在坐标轴上的正方形。 而 L2 正则对应的约束区域为 $x_1^2 + x_2^2 \le \eta$  ，其形状为圆心在坐标轴上的圆。

图像如下，可以看到从图像的角度来说，椭圆和 L1 对应的约束区域的交点在坐标轴上，而和圆的交点不在坐标轴上。 

![Laplace](https://gitee.com/EdwardElric_1683260718/picture_bed/raw/master/img/20200501134442.png)

# Todo \- 2020\-05\-01 14:10 – by ed L2减少共线性

L2的另一个作用是减少共线性。这对应线性模型是很重要的。

如线性回归，其参数估计为

$$
\hat{\beta} = (X^TX)^{-1}X^{T} y
$$ 

# References
1. [l1 相比于 l2 为什么容易获得稀疏解？ \- 知](https://www.zhihu.com/question/37096933)
