#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left,*right;
} Node;

Node* newNode(int x){
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->left = p->right = NULL;
    return p;
}

Node* buildBalancedBST(int arr[], int l, int r){
    if(l>r) return NULL;
    int mid = (l + r) / 2;
    Node* root = newNode(arr[mid]);
    root->left  = buildBalancedBST(arr, l, mid-1);
    root->right = buildBalancedBST(arr, mid+1, r);
    return root;
}

void levelOrder(Node* root, int n){
    if(root==NULL){ printf("Tree is empty.\n"); return; }
    Node** q = (Node**)malloc(sizeof(Node*) * n);
    int front = 0, rear = 0;
    q[rear++] = root;
    while(front < rear){
        Node* cur = q[front++];
        printf("%d ", cur->data);
        if(cur->left)  q[rear++] = cur->left;
        if(cur->right) q[rear++] = cur->right;
    }
    printf("\n");
    free(q);
}

int main(){
    int n;
    printf("Enter number of elements (n): ");
    if(scanf("%d",&n)!=1 || n<=0){ printf("Invalid n\n"); return 0; }

    int *arr = (int*)malloc(sizeof(int)*n);
    printf("Enter %d sorted integers (ascending) separated by space/newline:\n", n);
    for(int i=0;i<n;i++){
        if(scanf("%d",&arr[i])!=1){ printf("Invalid input\n"); free(arr); return 0; }
    }

    Node* root = buildBalancedBST(arr, 0, n-1);
    printf("Level-order traversal of the balanced BST:\n");
    levelOrder(root, n);

    free(arr);
    return 0;
}
