#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

Node* insert(Node* root, int val) {
    if (root == NULL) return createNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// ------------------ K-th SMALLEST ------------------

int kthSmallUtil(Node* root, int *k) {
    if (root == NULL) return -1;

    int left = kthSmallUtil(root->left, k);
    if (left != -1) return left;

    (*k)--;
    if (*k == 0) return root->data;

    return kthSmallUtil(root->right, k);
}

int kthSmallest(Node* root, int k) {
    return kthSmallUtil(root, &k);
}

// ------------------ K-th LARGEST ------------------

int kthLargeUtil(Node* root, int *k) {
    if (root == NULL) return -1;

    int right = kthLargeUtil(root->right, k);
    if (right != -1) return right;

    (*k)--;
    if (*k == 0) return root->data;

    return kthLargeUtil(root->left, k);
}

int kthLargest(Node* root, int k) {
    return kthLargeUtil(root, &k);
}

// ------------------ MAIN ------------------

int main() {
    int n, val, k;
    Node* root = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Enter k for k-th smallest: ");
    scanf("%d", &k);
    printf("k-th Smallest = %d\n", kthSmallest(root, k));

    printf("Enter k for k-th largest: ");
    scanf("%d", &k);
    printf("k-th Largest = %d\n", kthLargest(root, k));

    return 0;
}
