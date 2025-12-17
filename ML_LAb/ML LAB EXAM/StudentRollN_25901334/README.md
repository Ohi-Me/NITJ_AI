README – K-Means Clustering (DS3 Dataset :- https://www.kaggle.com/datasets/vjchoudhary7/customer-segmentation-tutorial-in-python)

Dataset

Name: Mall_Customers.csv

Features: CustomerID, Gender, Age, Annual Income (k$), Spending Score (1-100)

Data Preprocessing: Dropped unnecessary columns, checked missing values, scaled numeric features.




1️.Easy – Evaluate k via Elbow

Objective: Determine optimal k using Elbow Method.

Method: K-Means on scaled features (Age, Income, Spending Score), plot inertia vs k.

Result: Optimal k = 5.

Plots: Elbow plot, cluster scatter (2D visualization).




2️.Moderate – Cluster Profile

Objective: Create cluster profiles (mean/std) to understand characteristics.

Method: K-Means with k=5, add cluster labels, calculate mean & std per cluster.

Plots: Cluster mean bar plot, cluster std bar plot.

Insight: Shows segment characteristics like age, income, spending behavior.




3️.Hard – KMeans vs MiniBatchKMeans

Objective: Compare inertia, silhouette, and runtime.

Method: Fit both algorithms with k=5, evaluate metrics.

Plots: Inertia comparison, silhouette comparison.

Insight: MiniBatchKMeans is faster; KMeans slightly better cluster compactness.

Libraries Used: Python 3, Pandas, Matplotlib, Scikit-learn

Note: Runtime is optional, mainly for large datasets.
