
[toc]

# Sklearn label_binarize

这个函数是用来二元化标签的。

## 示例1: 标签为1的样本标签设为1，其它样本标签设为0

```
import numpy as np
from sklearn.preprocessing import label_binarize
data = np.array([1,0,2,1,3])
label_binarize(data, [1]) # 标签为1的样本为1，其它都是0
```

```
array([[1],
       [0],
       [0],
       [1],
       [0]])
```

## 示例2: 标签为1的样本标签设为[1,0]，[0,1] 其它样本标签设为 [0,0]

```
import numpy as np
from sklearn.preprocessing import label_binarize
data = np.array([1,0,2,1,3])
label_binarize(data, [1,2]) # 标签为1的样本为[1,0]，标签为2的样本为[0,1]
                            # 其它都是 [0, 0]
```

```
array([[1, 0],
       [0, 0],
       [0, 1],
       [1, 0],
       [0, 0]])
```

## 示例3: 用 label_binarize实现 one-hot（实际上one-hot用专门的）

```
import numpy as np
from sklearn.preprocessing import label_binarize
data = np.array([1,0,2,1,3])
label_binarize(data, list(set(data))) # 实现one-hot
```

```
array([[0, 1, 0, 0],
       [1, 0, 0, 0],
       [0, 0, 1, 0],
       [0, 1, 0, 0],
       [0, 0, 0, 1]])
```

# References
1. [sklearn.preprocessing.label_binarize — scikit-learn 0.22.2 documentation](https://scikit-learn.org/stable/modules/generated/sklearn.preprocessing.label_binarize.html#sklearn.preprocessing.label_binarize)
