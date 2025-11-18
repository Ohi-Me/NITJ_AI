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

// Build tree from level-order array
Node* build(int arr[], int n) {
    if(n == 0) return NULL;

    Node* nodes[n];
    for(int i=0; i<n; i++)
        nodes[i] = createNode(arr[i]);

    for(int i=0; i<n; i++) {
        if(nodes[i] != NULL) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            if(l < n) nodes[i]->left = nodes[l];
            if(r < n) nodes[i]->right = nodes[r];
        }
    }
    return nodes[0];
}

// Traversals
void preorder(Node* root) {
    if(!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if(!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node* root) {
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter values in level order (-1 for NULL):\n");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    Node* root = build(arr, n);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nInorder: ");
    inorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\n");
    return 0;
}
