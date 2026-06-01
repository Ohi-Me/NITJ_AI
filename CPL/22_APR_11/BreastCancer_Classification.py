# # Experiment 11
# # Breast Cancer Classification Using CUDA (RAPIDS cuML)

# ## Aim
# To implement GPU accelerated breast cancer classification using CUDA libraries.

# ## Theory
# Breast cancer classification using RAPIDS cuDF/cuML running on NVIDIA GPUs.

!nvidia-smi

import cudf
import cupy as cp
import matplotlib.pyplot as plt
from sklearn.datasets import load_breast_cancer
from cuml.model_selection import train_test_split
from cuml.ensemble import RandomForestClassifier
from cuml.metrics import accuracy_score

data=load_breast_cancer()
X=cudf.DataFrame(data.data,columns=data.feature_names)
y=cudf.Series(data.target)
print(X.shape)
X.head()

y.value_counts()

y.value_counts().to_pandas().plot(kind='bar')
plt.title('Class Distribution')
plt.show()

# ## Train Test Split

X_train,X_test,y_train,y_test=train_test_split(X,y,test_size=0.2,random_state=42)

# ## GPU Model Training

import time
start=time.time()
model=RandomForestClassifier(n_estimators=200,max_depth=12,random_state=42)
model.fit(X_train,y_train)
pred=model.predict(X_test)
gpu_time=time.time()-start
print('GPU Time:',gpu_time)

acc=accuracy_score(y_test,pred)
print('Accuracy =',float(acc)*100)

from sklearn.metrics import confusion_matrix
cm=confusion_matrix(y_test.to_pandas(),pred.to_pandas())
print(cm)

plt.imshow(cm)
plt.colorbar()
plt.title('Confusion Matrix')
plt.show()

import pandas as pd

fi = pd.Series(
    model.feature_importances_,
    index=X_train.columns
)

fi.sort_values(ascending=False).head(10).plot(kind='bar')
plt.title('Top Features')
plt.show()

# ## Result
# GPU accelerated classification completed successfully with high accuracy.