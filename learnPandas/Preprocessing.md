[toc]

## 6.3 Preprocessing data

这里的内容来自于 sklearn 的官方文档

[6.3. Preprocessing data — scikit-learn 0.22.1 documentation](https://scikit-learn.org/stable/modules/preprocessing.html#encoding-categorical-features)

### 6.3.4. Encoding categorical features

OridinalEncoder用来编码分类变量。将其编码为 0 到 n_categories - 1 的整数（这个和 LabelEncoder 分清，LabelEncoder 是用来编码 y 的）

这个函数是比较新的函数，低版本的 sklearn 中可能没有。0.19.0 版本中就没有。

#### OrdinalEncoder

下面的内容主要来自于 [sklearn.preprocessing.OrdinalEncoder — scikit-learn 0.22.1 documentation](https://scikit-learn.org/stable/modules/generated/sklearn.preprocessing.OrdinalEncoder.html#sklearn.preprocessing.OrdinalEncoder)

##### 原型 参数

```
class sklearn.preprocessing.OrdinalEncoder(categories='auto', dtype=<class 'numpy.float64'>)
```

- **categories: 'auto' or a list of array-like, default='auto'**
Categories (unique values) per feature:
    - 'auto' : Determine categories automatically from the training data.
    - list : 2-d list; categories[i] holds the categories expected in the ith column. The passed categories should not mix strings and numeric values, and should be sorted in case of numeric values.
- **dtype: number type, default np.float64**
Desired dtype of output.（可能参数常常会用到）

##### 属性

- categories_list of arrays
The categories of each feature determined during fitting (in order of the features in X and corresponding with the output of transform).

##### 示例

###### 1. 普通使用

这个类几乎不需要参数，基本上是直接使用即可。

```
from sklearn.preprocessing import OrdinalEncoder
encoder = OrdinalEncoder()
X = [['male', 'from US', 'uses Safari'], ['female', 'from Europe', 'uses Firefox']]
encoder.fit(X)

print(encoder.transform([['female', 'from US', 'uses Safari']]))
print(encoder.categories_)
```


###### 2. categories 参数

如果有的类在数据中没有出现，又想对这种类保留编码，可以使用 categories属性

如下面的示例中，对第一个特征添加一个 'gay' 类别

```
from sklearn.preprocessing import OrdinalEncoder
encoder = OrdinalEncoder([['male', 'female', 'gay'], # 添加了一个 'gay' 类型
                        ['from US', 'from Europe'],
                        ['uses Safari', 'uses Firefox']])
X = [['male', 'from US', 'uses Safari'], ['female', 'from Europe', 'uses Firefox']]
encoder.fit(X)

print(encoder.transform([['female', 'from US', 'uses Safari']]))
print(encoder.categories_)
```

## 6.9 Transforming the prediction target (y)

[6.9. Transforming the prediction target (y) — scikit-learn 0.22.1 documentation](https://scikit-learn.org/stable/modules/preprocessing_targets.html#)

### 6.9.2 Label Encoding

#### LabelEncoder

注意这个是用来编码 y 的，用 OrdinalEncoder 来编码 X

```
le = preprocessing.LabelEncoder()
le.fit(["paris", "paris", "tokyo", "amsterdam"])

list(le.classes_)
le.transform(["tokyo", "tokyo", "paris"])
list(le.inverse_transform([2, 2, 1]))
```
