#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

typedef struct Queue {
    Node* arr[100];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, Node* x) {
    if (q->rear == 99) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = x;
}

Node* dequeue(Queue* q) {
    if (isEmpty(q)) return NULL;
    Node* x = q->arr[q->front];
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;
    return x;
}

Node* createNode(int val) {
    if (val == -1) return NULL;
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

// Build binary tree from level-order
Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    Node* nodes[n];
    for (int i = 0; i < n; i++)
        nodes[i] = createNode(arr[i]);

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            if (l < n) nodes[i]->left = nodes[l];
            if (r < n) nodes[i]->right = nodes[r];
        }
    }
    return nodes[0];
}

// Level-Order Traversal using queue
void levelOrder(Node* root) {
    if (root == NULL) return;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    printf("\nLevel-order: ");

    while (!isEmpty(&q)) {
        Node* cur = dequeue(&q);
        printf("%d ", cur->data);

        if (cur->left)  enqueue(&q, cur->left);
        if (cur->right) enqueue(&q, cur->right);
    }
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d values in level order (-1 for NULL):\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    levelOrder(root);

    return 0;
}
