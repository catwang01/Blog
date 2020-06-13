[toc]

# FM 模型

## 线性模型及其改进

传统的推荐系统中，比较常用的模型是 LR 模型。LR 模型本质上来说是线性模型，线性模型可以表示为下面的形式：

$$
\hat{y} = w_0 + \sum_{i=1}^{n} w_i x_{i}
$$

线性模型的优点是速度性，并且可解释性强。缺点是表达能力弱。

为了提高普通线性模型的表达能力，可以在线性模型中加入交互项：

$$
\hat{y} = w_0 + \sum_{i=1}^{n} w_i x_i + \sum_{i=1}^{n} \sum_{j=i+1}^{n} w_{i,j} x_i x_j \quad\quad (1)
$$ 

注意，这里的交互项不包含 $x_i^2$ 这样的项。

上面的模型，实际上等价于 SVM 在 kernel 为多项式核的情况，因此上面的模式也被称为 SVM 模型。

## SVM模型的缺点

加入交互项之后，虽然模型的表达能力增强，但是有下面的两个问题：

1. 计算复杂度比较高。一共有 n(n-1) / 2 个参数
2. 在数据很稀疏的条件下表现并不好。考虑是对类别变量进行 one-hot encoding 的情况，如果有两个类别在样本中没有同时出现过，那么  $x_i x_j$  在样本中总是为 0，因此 $\frac{\partial \hat{y}}{\partial w_{i,j}}  \equiv 0$，$w_{i,j}$  完全无法更新。

## FM 模型

由于上述的两个问题的存在，因此进行下面的改进，

假设第 $i$ 个特征可以表示为一个 k 维的向量 $v_i \in \mathbb{R}^k$ 。 $k$ 是隐向量的长度，是一个需要提前给定的超参数。

而 $w_{i,j}$  是度量第 i 个特征和第 j 个特征的交互作用的参数。 令 $w_{i,j} = \left\langle v_i, v_j \right\rangle$，因此 $(1)$  式就变成了

$$
\hat{y} = w_{0} + \sum_{i=1}^{n} w_{i} x_{i} + \sum_{i=1}^{n} \sum_{j=i+1}^{n}\left\langle v_{i}, v_{j}\right\rangle x_{i} x_{j} \quad \quad ( 2 )
$$ 

此时模型的参数为

1. 常数项 $w_0$ 
2. 线性部分的参数，合写成一个向量 $w_1, \ldots, w_n$ 
3. 交互项部分的参数 $v_1, \ldots, v_n$ ，将其按行排列得到一个矩阵  $V = \begin{pmatrix} v_1^T\\ \vdots\\ v_n^T  \end{pmatrix} \in R^{n \times k}$

## $v_i$ 的解释

上文中有提到，$v_i$ 是特征 i 的一个 k 维表示。实际上是一个 k 维的 embedding 。这主要是针对离散变量 one-hot encoding 之后的特征来说的。

假如有一列变量是 user_id，有 5 个取值，那么在 one-hot encoding 之后就有 5 个特征。每个特征都对应一个隐向量 $v_i$，这个隐向量实际上就是用户在 $k$ 维空间的一个 embedding。

## 复杂度优化

(2) 式的计算复杂度为 $O(kn^2)$ ，主要时间开销在最后一项 $\sum_{i=1}^{n} \sum_{j=i+1}^{n}\left\langle v_{i}, v_{j}\right\rangle x_{i} x_{j}$ ，其中计算 $\left\langle v_i, v_j\right\rangle x_i x_j$ 的时间复杂度为 $O(k)$ ，有两个求和号  $\sum_{i=1}^{n} \sum_{j=i+1}^{n}$  ，因此最后一项总的计算时间复杂度为 $O(kn^2)$ 

通过数学变换，可以将时间复杂度降低到 $O(kn)$ ，变换如下

$$
\begin{aligned}
\sum_{i=1}^{n} \sum_{j=i+1}^{n}\left\langle v_{i}, v_{j}\right\rangle x_{i} x_{j}  
&= \frac{1}{2} \left( \sum_{i=1}^{n} \sum_{j=1}^{n}  \left\langle v_i, v_j \right\rangle x_i x_j  - \sum_{i=1}^{n} \left\langle v_i, v_i \right\rangle x_i^2 \right) \\
&= \frac{1}{2} \left( \sum_{i=1}^{n} \sum_{j=1}^{n}  \sum_{f=1}^{k}  v_{i,f} v_{j,f} x_i x_j  - \sum_{i=1}^{n} \sum_{f=1}^{k} v_{i,f}^2 x_i^2 \right) \\
&= \frac{1}{2} \sum_{f=1}^{k} \left( \sum_{i=1}^{n} \sum_{j=1}^{n}  v_{i,f} v_{j,f} x_i x_j  - \sum_{i=1}^{n} v_{i,f}^2 x_i^2 \right) \\
&= \frac{1}{2} \sum_{f=1}^{k} \left( \left(\sum_{i=1}^{n} v_{i,f} x_i \right)^2 - \sum_{i=1}^{n} v_{i,f}^2 x_i^2 \right) \\
.\end{aligned}
$$ 

可以看到，变换后的式子的时间复杂度为 $O(kn)$ ，其中计算 $\left(\sum_{i=1}^{n} v_{i,f} x_i \right)^2 - \sum_{i=1}^{n} v_{i,f}^2 x_i^2$ 的时间复杂度为 $O(n)$ ，由于最外层的求和号 $\sum_{f=1}^{k}$  ，因此时间复杂度为 $O(kn)$ 

## 求导

根据 chain rule，$\frac{\partial l(y, \hat{y})}{\partial \theta} = \frac{\partial l(y, \hat{y})}{\partial \hat{y}} \frac{\partial \hat{y}}{\partial \theta}$  ，其中 $\frac{\partial l(y, \hat{y})}{\partial \hat{y}}$  这个取决于具体 Loss 的形式。

而 $\frac{\partial \hat{y}}{\partial \theta}$  的计算如下:

$$
\frac{\partial}{\partial \theta} \hat{y}=\left\{\begin{array}{ll}
1, & \text { if } \theta \text { is } w_{0} \\
x_{i}, & \text { if } \theta \text { is } w_{i} \\
x_{i} \sum_{j=1}^{n} v_{j, f} x_{j}-v_{i, f} x_{i}^{2}, & \text { if } \theta \text { is } v_{i, f}
\end{array}\right.
$$

其中 $\sum_{j=1}^{n}  v_{j,f} x_j$  可以在计算 $\hat{y}$ 时计算好。因此，$w_0, w_1, \ldots, w_n, v_{i,j}$ 均可在 $O(1)$ 时间复杂度内计算出来。因此使用一个样本去计算梯度的时间复杂度为  $O(kn)$ （因为主要的时间是还是更新  $v_{i,j}$ 因此只计算 $v_{i,j}$ 的时间。有 $kn$ 个 $v_{i,j}$  因此时间复杂度为 $O(kn)$ ）

## FM 和 MF 的比较

先给出结论： MF 模型是一种特殊的 FM 模型。
将 FM 模型的常数项和线性项去掉，并取 loss 为 MSE，使用 L2 正则项，并对 user_id 和 item_id 进行 one-hot encoding 作为特征。

<!--# Todo - 2020-06-13 17:18 -- by  ed 之后再看。符号有点混了 -->

<!--MF (matrix factorization) 模型的损失函数如下：-->

<!--$$-->
<!--L = \sum_{(i,j) \in S} (r_{i,j} - \hat{r}_{i,j})^2 + \lambda (\| u_i \|^2 + \| v_j \|^2 )-->
<!--$$ -->

<!--其中 $r_{i,j}$  是用户 $i$ 对 物品 $j$ 的打分，$u_i$ 是用户 $i$ 的隐向量， $v_j$ 是物品 $j$ 的隐向量，$\hat{r}_{i,j} = u^T_iv_j$ -->

<!--而 FM 模型的公式为 -->

<!--$$-->
<!--\hat{y} = w_0 + \sum_{i=1}^{n} w_i x_i + \sum_{i=1}^{n} \sum_{j=i+1}^{n} \left\langle v_i,v_j \right\rangle x_i x_j-->
<!--$$ -->


<!--如果将数据整理成 (user_id, item_id, rating) 这样的三元组。并对 user_id 和 item_id 进行 one-hot encoding。-->

<!--将 user_id encoding 的特征记为  $x^u \in \mathbb{R}^{n_u}$ ，则用户 $i$ 对应的  $x^u$  满足 -->
<!--$-->
<!--x^u_t = \begin{cases} -->
<!--1 \quad t=i \\ -->
<!--0 \quad t \neq i -->
<!--\end{cases}-->
<!--$ -->

<!--将 item_id encoding 得到的特征记为 $x^v \in \mathbb{R}^{n_v}$ ，则物品 $j$ 对应的  $x^v$  满足-->
<!--$-->
<!--x^v_t = \begin{cases} -->
<!--1 \quad t=j \\ -->
<!--0 \quad t \neq j-->
<!--\end{cases}-->
<!--$ -->
<!--，-->

<!--则 $(i, j, r_{i,j})$ 这样的三元组可以对应 $(x, y)$ ，其中 $x = [x^u, x^v] \in \mathbb{R}^{n_u + n_v}, y = r_{i,j}$-->

<!--将 FM 公式中的常数项和线性项去掉，并将 $(x,y)$ 带入，有-->

<!--$$-->
<!--\hat{y} = \sum_{t=1}^{n_u+n_v} \sum_{s=t+1}^{n_u+n_v}  \left\langle v_t, v_s \right\rangle x_t, x_s-->
<!--$$ -->

<!--由于 $(x,y)$ 表示的是 用户  $i$ 对物品  $j$ 的点击。因此  $x^u$ 中只有  $x^u_i=1$ ， $x^v$ 中只有  $x^v_j=1$ ，求和号中除了 $t=i, v=n_u+j$ 外，其它都为0，即-->

<!--$$-->
<!--\hat{y} = \left\langle v_i, v_{n_u+j} \right\rangle -->
<!--$$ -->

<!--令 $v_i = u_i, v_j = v_j$ -->

## FM 的优点

1. 可以在线性时间 $O(kn)$ 内完成计算，计算效率高。
2. 即使原始数据中不存在的特征组合 ，也可以学习到权重 $w_{i,j} = \left\langle v_i, v_j \right\rangle$，因此泛化能力强。
3. 和 MF 相比，使用了除 user_id 和 item_id 之外的信息，因此效果更好。



