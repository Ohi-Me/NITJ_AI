#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
    int height;
} Node;

/* ---------- CREATE NODE ---------- */
Node* newNode(int x) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->left = p->right = NULL;
    p->height = 1;
    return p;
}

/* ---------- HEIGHT FUNCTION ---------- */
int height(Node* root) {
    return root ? root->height : 0;
}

/* ---------- BALANCE FACTOR ---------- */
int getBF(Node* root) {
    if (!root) return 0;
    return height(root->left) - height(root->right);
}

/* ---------- ROTATIONS ---------- */
Node* rightRotate(Node* y) {
    printf("Rotation: Right Rotation (LL Case)\n");

    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (height(y->left) > height(y->right) ?
                     height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ?
                     height(x->left) : height(x->right));

    return x;
}

Node* leftRotate(Node* x) {
    printf("Rotation: Left Rotation (RR Case)\n");

    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (height(x->left) > height(x->right) ?
                     height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ?
                     height(y->left) : height(y->right));

    return y;
}

/* ---------- INSERT IN AVL TREE ---------- */
Node* insert(Node* root, int key) {
    if (root == NULL) {
        printf("Inserted %d\n", key);
        return newNode(key);
    }

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else {
        printf("Duplicate ignored: %d\n", key);
        return root;
    }

    root->height = 1 + (height(root->left) > height(root->right) ?
                        height(root->left) : height(root->right));

    int bf = getBF(root);

    /* ---------- ROTATION CASES ---------- */
    if (bf > 1 && key < root->left->data) {
        return rightRotate(root);         // LL
    }

    if (bf < -1 && key > root->right->data) {
        return leftRotate(root);          // RR
    }

    if (bf > 1 && key > root->left->data) {  // LR
        printf("Rotation: Left-Right Rotation (LR Case)\n");
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (bf < -1 && key < root->right->data) { // RL
        printf("Rotation: Right-Left Rotation (RL Case)\n");
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

/* ---------- PRINT BALANCE FACTOR AFTER INSERTION ---------- */
void printBF(Node* root) {
    if (!root) return;
    printBF(root->left);
    printf("Node %d → BF = %d\n", root->data, getBF(root));
    printBF(root->right);
}

int main() {
    int n, x;
    Node* root = NULL;

    printf("Enter number of insertions: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        printf("\n=== Inserting %d ===\n", x);
        root = insert(root, x);

        printf("Balance Factors now:\n");
        printBF(root);
        printf("-----------------------\n");
    }

    return 0;
}
