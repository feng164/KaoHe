# 一.区别与优化

## 1.实现方式:

### (1)sklearn

- 内部使用了高度优化的数值计算库（如`scipy`、`numpy`等），并且可能利用了底层的C或Fortran代码来加速计算。
- `sklearn`的`LinearRegression`默认使用解析解（最小二乘法）来求解线性回归问题，而不是梯度下降。解析解通过直接求解正规方程来找到最优解，计算复杂度为*O*(*n*2)，其中*n*是特征数量。

### (2)手动实现

- 手动实现了线性回归的前向传播（`compute_model_output`）、损失计算（`compute_cost`）、梯度计算（`compute_gradient`）和梯度下降（`gradient_descent`）。
- 使用了纯Python代码，依赖于`numpy`进行矩阵运算。
## 2.性能优化

### (1)sklearn

- 对于小到中等规模的数据集，`sklearn`的`LinearRegression`使用解析解（最小二乘法），计算效率更高。

- 对于大规模数据集，`sklearn`提供了`SGDRegressor`，使用随机梯度下降（SGD），并且支持多种优化算法（如Momentum、Nesterov等）。

- `sklearn`的实现还支持多线程计算，可以利用多核CPU加速。

### (2)手动
- 使用了简单的梯度下降算法，每次迭代更新权重和偏置。
- 没有使用任何加速技术，如动量、自适应学习率等。

## 3.功能丰富性

### (1)sklearn

- 提供了丰富的功能，如模型评估指标（`score`方法计算*R*2）、正则化（`Ridge`、`Lasso`等）、交叉验证等。
- 支持多种输入数据格式（如稀疏矩阵），并且可以自动处理数据的标准化和归一化。

### (2)手动

- 只实现了基本的线性回归功能，包括前向传播、损失计算、梯度下降和预测。
- 没有提供模型评估指标（如*R*2、均方误差等）。
- 不支持正则化（如L1或L2正则化）。
## 4.数值稳定性
### (1)sklearn

- 内部进行了数值稳定性优化，例如在求解正规方程时，会使用奇异值分解（SVD）等方法来避免矩阵不可逆的情况。
- 提供了参数调整选项，如`fit_intercept`（是否拟合截距项）、`normalize`（是否对数据进行归一化）等，以提高模型的数值稳定性。
### (2)手动

- 没有对数值稳定性进行特别处理，比如在梯度下降中，没有检查学习率是否过大导致的数值不稳定。

## 5. **易用性**

### (1)sklearn

- 提供了非常简洁的API，用户只需调用`fit`方法训练模型，调用`predict`方法进行预测，非常易于使用。

### (2)手动

- 需要手动编写代码来实现线性回归的各个步骤。

## 6. **扩展性**

### (1)sklearn

- 支持多特征输入，并且可以轻松扩展到更复杂的模型（如多项式回归、岭回归等）。
- 提供了丰富的扩展接口，用户可以自定义损失函数、优化算法等。

### (2)手动

- 代码结构较为简单，扩展性有限。





# 二.代码逻辑与数学实现

### **1. `LinearRegression`（最小二乘法实现）**

- ####  数学原理

线性回归的目标是找到一个线性模型 \( y = Xw + b \)，使得预测值 \( \hat{y} \) 尽可能接近真实值 \( y \)。最小二乘法通过最小化均方误差（MSE）来求解最优参数 \( w \) 和 \( b \)。

均方误差（MSE）定义为：$\text{MSE} = \frac{1}{2m} \sum_{i=1}^{m} (X_i w + b - y_i)^2$
其中, m 是样本数量，$x_i$ 是第 i 个样本的特征向量，$y_i$ 是第i个样本的真实值。

通过求解正规方程（Normal Equation）可以得到最优解：$w = (X^T X)^{-1} X^T y$
其中，$ X^T  $是特征矩阵 $ X $ 的转置，$(X^T X)^{-1}$ 是矩阵 $ X^T X$ 的逆矩阵。

- #### **代码逻辑**

  - **数据预处理**：

    - 如果`fit_intercept=True`，则在特征矩阵 \( X \) 中添加一列全为1的列，用于计算偏置项 \( b \)。

    - 如果`normalize=True`，则对特征进行归一化处理。

  - **求解正规方程**：

    - 使用`numpy.linalg.lstsq`或`scipy.linalg.solve`等方法求解正规方程。

    - 如果矩阵 \( X^T X \) 不可逆（奇异矩阵），则使用伪逆（`numpy.linalg.pinv`）来求解。

以下是核心代码逻辑：

```python
import numpy as np

class LinearRegression:
    def __init__(self, fit_intercept=True, normalize=False):
        self.fit_intercept = fit_intercept
        self.normalize = normalize

    def fit(self, X, y):
        if self.fit_intercept:
            X = np.hstack([np.ones((X.shape[0], 1)), X])  # 添加偏置项
        if self.normalize:
            X = self._normalize(X)
        self.coef_ = np.linalg.lstsq(X, y, rcond=None)[0]  # 求解正规方程
        if self.fit_intercept:
            self.intercept_ = self.coef_[0]
            self.coef_ = self.coef_[1:]
        else:
            self.intercept_ = 0.0

    def predict(self, X):
        if self.fit_intercept:
            X = np.hstack([np.ones((X.shape[0], 1)), X])
        return np.dot(X, np.hstack([self.intercept_, self.coef_]))

    def _normalize(self, X):
        # 归一化处理
        return (X - np.mean(X, axis=0)) / np.linalg.norm(X, axis=0)
```

---

### **2. `SGDRegressor`（随机梯度下降实现）**

- #### **数学原理**

随机梯度下降（SGD）是一种迭代优化算法，通过逐步更新模型参数来最小化损失函数。对于线性回归，损失函数通常为均方误差（MSE）。

在每次迭代中，SGD随机选择一个样本 \( (X_i, y_i) \)，并计算梯度：

$\frac{\partial \text{MSE}}{\partial w} = X_i^T (X_i w + b - y_i)$
$\frac{\partial \text{MSE}}{\partial b} = X_i w + b - y_i$
然后根据学习率 \( \alpha \) 更新参数：
$w = w - \alpha \frac{\partial \text{MSE}}{\partial w}$
$b = b - \alpha \frac{\partial \text{MSE}}{\partial b}$

- #### **代码逻辑**

`sklearn.linear_model.SGDRegressor`的实现基于随机梯度下降算法，其主要步骤如下：

1. **初始化参数**：
   - 初始化权重 \( w \) 和偏置 \( b \)（通常为0或随机值）。
   - 设置学习率（可以是固定值，也可以是动态调整的）。

2. **迭代更新**：
   - 在每次迭代中，随机选择一个样本或一个小批量样本。
   - 计算梯度并更新权重和偏置。

3. **支持多种优化算法**：
   - `SGDRegressor`支持多种优化算法，如Momentum、Nesterov等，通过`momentum`参数控制。

以下是核心代码逻辑：

```python
import numpy as np

class SGDRegressor:
    def __init__(self, learning_rate=0.01, max_iter=1000, fit_intercept=True):
        self.learning_rate = learning_rate
        self.max_iter = max_iter
        self.fit_intercept = fit_intercept

    def fit(self, X, y):
        n_samples, n_features = X.shape
        if self.fit_intercept:
            X = np.hstack([np.ones((n_samples, 1)), X])  # 添加偏置项
        self.coef_ = np.zeros(n_features + self.fit_intercept)

        for _ in range(self.max_iter):
            for i in range(n_samples):
                xi = X[i]
                yi = y[i]
                prediction = np.dot(xi, self.coef_)
                error = prediction - yi
                gradient = xi * error
                self.coef_ -= self.learning_rate * gradient

        if self.fit_intercept:
            self.intercept_ = self.coef_[0]
            self.coef_ = self.coef_[1:]
        else:
            self.intercept_ = 0.0

    def predict(self, X):
        if self.fit_intercept:
            X = np.hstack([np.ones((X.shape[0], 1)), X])
        return np.dot(X, np.hstack([self.intercept_, self.coef_]))
```

---

### **3. 其他优化和功能**

#### **(1)正则化**

`sklearn`还提供了带有正则化的线性回归模型，如`Ridge`（L2正则化）和`Lasso`（L1正则化）。这些模型通过在损失函数中添加正则化项来防止过拟合。

- **Ridge回归**：
  $\text{Loss} = \frac{1}{2m} \sum_{i=1}^{m} (X_i w + b - y_i)^2 + \alpha \|w\|_2^2$
- **Lasso回归**：
  $\text{Loss} = \frac{1}{2m} \sum_{i=1}^{m} (X_i w + b - y_i)^2 + \alpha \|w\|_1$

#### **(2)多线程支持**

`sklearn`的实现支持多线程计算，可以通过设置`n_jobs`参数来利用多核CPU加速计算。

#### **(3)模型评估**

`sklearn`提供了丰富的模型评估指标，如均方误差（MSE）、决定系数（\(R^2\)）等。这些指标可以通过`sklearn.metrics`模块计算。





