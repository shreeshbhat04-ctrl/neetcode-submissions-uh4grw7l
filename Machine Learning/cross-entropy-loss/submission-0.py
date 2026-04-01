import numpy as np
from numpy.typing import NDArray


class Solution:

    def binary_cross_entropy(self, y_true: NDArray[np.float64], y_pred: NDArray[np.float64]) -> float:
        epsi=1e-7
        y_pred=np.clip(y_pred,epsi,1-epsi)
        Loss=-np.mean(y_true*np.log(y_pred)+(1-y_true)*np.log(1-y_pred))
        return np.round(Loss,4)

    def categorical_cross_entropy(self, y_true: NDArray[np.float64], y_pred: NDArray[np.float64]) -> float:
        epsi=1e-7
        y_pred=np.clip(y_pred,epsi,1-epsi)
        Loss=-np.mean(np.sum(y_true*np.log(y_pred),axis=1))
        return np.round(Loss,4)

