#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
    int height;
} Node;

/* Create Node */
Node* newNode(int x) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = x;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

/* Height */
int height(Node* root) {
    return root ? root->height : 0;
}

/* Balance Factor */
int BF(Node* root) {
    return height(root->left) - height(root->right);
}

/* Update Height */
void updateHeight(Node* root) {
    root->height = 1 + (height(root->left) > height(root->right)
                        ? height(root->left) : height(root->right));
}

/* ---------- Rotations ---------- */
Node* rightRotate(Node* y) {
    printf("Rotation: Right (LL)\n");
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

Node* leftRotate(Node* x) {
    printf("Rotation: Left (RR)\n");
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

/* ---------- AVL Insert ---------- */
Node* insert(Node* root, int key) {
    if (!root) return newNode(key);

    if (key < root->data) root->left = insert(root->left, key);
    else if (key > root->data) root->right = insert(root->right, key);
    else return root;  // no duplicates

    updateHeight(root);

    int bf = BF(root);

    // LL
    if (bf > 1 && key < root->left->data)
        return rightRotate(root);

    // RR
    if (bf < -1 && key > root->right->data)
        return leftRotate(root);

    // LR
    if (bf > 1 && key > root->left->data) {
        printf("Rotation: Left-Right (LR)\n");
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL
    if (bf < -1 && key < root->right->data) {
        printf("Rotation: Right-Left (RL)\n");
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

/* Find inorder successor */
Node* minValueNode(Node* root) {
    while (root->left) root = root->left;
    return root;
}

/* ---------- AVL Delete ---------- */
Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                free(root);
                return NULL;
            } else {
                *root = *temp;
                free(temp);
            }
        } else {
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (!root) return root;

    updateHeight(root);

    int bf = BF(root);

    // LL
    if (bf > 1 && BF(root->left) >= 0)
        return rightRotate(root);

    // LR
    if (bf > 1 && BF(root->left) < 0) {
        printf("Rotation: Left-Right (LR)\n");
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR
    if (bf < -1 && BF(root->right) <= 0)
        return leftRotate(root);

    // RL
    if (bf < -1 && BF(root->right) > 0) {
        printf("Rotation: Right-Left (RL)\n");
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

/* ---------- Print Inorder ---------- */
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int n, x, d;

    /* Insert section */
    printf("Enter number of insertions: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        printf("\nInserting %d...\n", x);
        root = insert(root, x);
        printf("Current tree height: %d\n", height(root));
    }

    /* Delete section */
    printf("\nEnter number of deletions: ");
    scanf("%d", &d);

    printf("Enter values to delete:\n");
    for (int i = 0; i < d; i++) {
        scanf("%d", &x);
        printf("\nDeleting %d...\n", x);
        root = deleteNode(root, x);
        printf("Height after deletion: %d\n", height(root));
    }

    printf("\nFinal Tree (Inorder): ");
    inorder(root);
    printf("\n");

    return 0;
}
