#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int x) {
    if(x == -1) return NULL;
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

// Build binary tree from level-order input
Node* buildTree(int arr[], int n) {
    if(n == 0) return NULL;

    Node* nodes[n];
    for(int i = 0; i < n; i++)
        nodes[i] = createNode(arr[i]);

    for(int i = 0; i < n; i++) {
        if(nodes[i] != NULL) {
            int left = 2*i + 1;
            int right = 2*i + 2;
            if(left < n) nodes[i]->left = nodes[left];
            if(right < n) nodes[i]->right = nodes[right];
        }
    }
    return nodes[0];
}

// Height of tree
int height(Node* root) {
    if(root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

// Count leaf nodes
int countLeaves(Node* root) {
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d node values in level order (-1 for NULL):\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    printf("\nHeight of Tree: %d\n", height(root));
    printf("Leaf Nodes: %d\n", countLeaves(root));

    return 0;
}
