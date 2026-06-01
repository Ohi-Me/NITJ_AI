# # 🚀 Titanic Survival Prediction (Python + CUDA GPU)
# Using RAPIDS (cuDF + cuML)

# ## 1️⃣ Imports

import cudf
import cupy as cp
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

from cuml.model_selection import train_test_split
from cuml.ensemble import RandomForestClassifier
from cuml.tree import DecisionTreeClassifier

from sklearn.metrics import (
    confusion_matrix, classification_report,
    roc_curve, roc_auc_score, accuracy_score
)

# ## 2️⃣ Load Dataset (GPU)

df = cudf.read_csv("titanic.csv")
df.head()

# ## 3️⃣ EDA (Visualization)

pdf = df.to_pandas()

sns.countplot(x='Survived', data=pdf)
plt.title("Survival Count")
plt.show()

sns.barplot(x='Sex', y='Survived', data=pdf)
plt.title("Survival by Gender")
plt.show()

sns.histplot(pdf['Age'].dropna(), bins=30, kde=True)
plt.title("Age Distribution")
plt.show()

# ## 4️⃣ Preprocessing (GPU)

df['Age'] = df['Age'].fillna(df['Age'].median())
df['Embarked'] = df['Embarked'].fillna(df['Embarked'].mode()[0])

df = df.drop(columns=['Cabin'])

df['Sex'] = df['Sex'].astype('category').cat.codes
df['Embarked'] = df['Embarked'].astype('category').cat.codes

df = df.drop(columns=['Name', 'Ticket', 'PassengerId'])

# ## 5️⃣ Train-Test Split

X = df.drop(columns=['Survived'])
y = df['Survived']

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)

# ## 6️⃣ Train Models (GPU)

dt = DecisionTreeClassifier(max_depth=5)
dt.fit(X_train, y_train)

y_pred_dt = dt.predict(X_test)
y_prob_dt = dt.predict_proba(X_test)[:,1]

rf = RandomForestClassifier(n_estimators=100)
rf.fit(X_train, y_train)

y_pred_rf = rf.predict(X_test)
y_prob_rf = rf.predict_proba(X_test)[:,1]

# ## 7️⃣ Convert to CPU

y_test_cpu = y_test.to_pandas()
y_pred_dt_cpu = y_pred_dt.to_pandas()
y_pred_rf_cpu = y_pred_rf.to_pandas()

y_prob_dt_cpu = y_prob_dt.to_pandas()
y_prob_rf_cpu = y_prob_rf.to_pandas()

# ## 8️⃣ Accuracy

print("DT Accuracy:", accuracy_score(y_test_cpu, y_pred_dt_cpu))
print("RF Accuracy:", accuracy_score(y_test_cpu, y_pred_rf_cpu))

# ## 9️⃣ Confusion Matrix

cm = confusion_matrix(y_test_cpu, y_pred_dt_cpu)

sns.heatmap(cm, annot=True, fmt='d')
plt.title("Decision Tree Confusion Matrix")
plt.show()

# ## 🔟 Classification Report

print(classification_report(y_test_cpu, y_pred_dt_cpu))

# ## 1️⃣1️⃣ ROC Curve

fpr_dt, tpr_dt, _ = roc_curve(y_test_cpu, y_prob_dt_cpu)
fpr_rf, tpr_rf, _ = roc_curve(y_test_cpu, y_prob_rf_cpu)

plt.plot(fpr_dt, tpr_dt, label="Decision Tree")
plt.plot(fpr_rf, tpr_rf, label="Random Forest")
plt.plot([0,1], [0,1], 'k--')

plt.xlabel("False Positive Rate")
plt.ylabel("True Positive Rate")
plt.title("ROC Curve")
plt.legend()
plt.show()

# ## 1️⃣2️⃣ ROC-AUC Score

print("DT AUC:", roc_auc_score(y_test_cpu, y_prob_dt_cpu))
print("RF AUC:", roc_auc_score(y_test_cpu, y_prob_rf_cpu))
