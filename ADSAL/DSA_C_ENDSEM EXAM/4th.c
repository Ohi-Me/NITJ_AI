#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct qnode{
    struct node *data;
    struct qnode *next;
};

struct qnode *front=NULL,*rear=NULL;

struct node* newNode(int x){
    struct node *t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    t->left=t->right=NULL;
    return t;
}

void enqueue(struct node *x){
    struct qnode *t=(struct qnode*)malloc(sizeof(struct qnode));
    t->data=x;
    t->next=NULL;
    if(!rear){
        front=rear=t;
        return;
    }
    rear->next=t;
    rear=t;
}

struct node* dequeue(){
    if(!front) return NULL;
    struct qnode *t=front;
    struct node *x=t->data;
    front=front->next;
    if(!front) rear=NULL;
    free(t);
    return x;
}

void bfs(struct node *root){
    if(!root) return;
    enqueue(root);
    while(front){
        struct node *t=dequeue();
        printf("%d ",t->data);
        if(t->left) enqueue(t->left);
        if(t->right) enqueue(t->right);
    }
}

int main(){
    struct node *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);

    bfs(root);
    return 0;
}
