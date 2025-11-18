#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int x) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->left = p->right = NULL;
    return p;
}

/* ---------- LEVEL ORDER INSERTION ---------- */
Node* insertLevelOrder(Node* root, int x) {
    Node* node = newNode(x);

    if (root == NULL)
        return node;

    // queue for BFS
    Node* q[1000];
    int front = 0, rear = 0;

    q[rear++] = root;

    while (front < rear) {
        Node* temp = q[front++];

        if (temp->left == NULL) {
            temp->left = node;
            break;
        } 
        else if (temp->right == NULL) {
            temp->right = node;
            break;
        }
        else {
            q[rear++] = temp->left;
            q[rear++] = temp->right;
        }
    }

    return root;
}

/* ---------- HEIGHT ---------- */
int height(Node* root) {
    if (!root) return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + (lh > rh ? lh : rh);
}

/* ---------- CHECK BALANCE & PRINT BALANCE FACTOR ---------- */
int checkBalanced(Node* root) {
    if (!root) return 1;

    int lh = height(root->left);
    int rh = height(root->right);

    int bf = lh - rh;
    printf("Node %d → Balance Factor = %d\n", root->data, bf);

    if (abs(bf) > 1)
        return 0;

    return checkBalanced(root->left) && checkBalanced(root->right);
}

int main() {
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size\n");
        return 0;
    }

    Node* root = NULL;

    printf("Enter %d values (level-order):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insertLevelOrder(root, x);
    }

    printf("\nBalance Factors:\n");
    int ok = checkBalanced(root);

    printf("\nTree is %s\n", ok ? "HEIGHT-BALANCED (AVL)" : "NOT BALANCED");

    return 0;
}
