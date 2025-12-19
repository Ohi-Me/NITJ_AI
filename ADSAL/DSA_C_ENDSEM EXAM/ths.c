#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left,*right;
    int height;
};

int max(int a,int b){ return a>b?a:b; }

int height(struct node *n){
    if(!n) return 0;
    return n->height;
}

struct node* newNode(int x){
    struct node *t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    t->left=t->right=NULL;
    t->height=1;
    return t;
}

struct node* rightRotate(struct node *y){
    struct node *x=y->left;
    struct node *t2=x->right;

    x->right=y;
    y->left=t2;

    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;

    return x;
}

struct node* leftRotate(struct node *x){
    struct node *y=x->right;
    struct node *t2=y->left;

    y->left=x;
    x->right=t2;

    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;

    return y;
}

int getBalance(struct node *n){
    if(!n) return 0;
    return height(n->left)-height(n->right);
}

struct node* minValueNode(struct node *n){
    while(n->left) n=n->left;
    return n;
}

struct node* insert(struct node *node,int key){
    if(!node) return newNode(key);

    if(key<node->data)
        node->left=insert(node->left,key);
    else if(key>node->data)
        node->right=insert(node->right,key);
    else
        return node;

    node->height=1+max(height(node->left),height(node->right));
    int bal=getBalance(node);

    if(bal>1 && key<node->left->data) return rightRotate(node);
    if(bal<-1 && key>node->right->data) return leftRotate(node);
    if(bal>1 && key>node->left->data){
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }
    if(bal<-1 && key<node->right->data){
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

struct node* deleteNode(struct node *root,int key){
    if(!root) return root;

    if(key<root->data)
        root->left=deleteNode(root->left,key);
    else if(key>root->data)
        root->right=deleteNode(root->right,key);
    else{
        if(!root->left || !root->right){
            struct node *t=root->left?root->left:root->right;
            if(!t){
                t=root;
                root=NULL;
            }else
                *root=*t;
            free(t);
        }else{
            struct node *t=minValueNode(root->right);
            root->data=t->data;
            root->right=deleteNode(root->right,t->data);
        }
    }

    if(!root) return root;

    root->height=1+max(height(root->left),height(root->right));
    int bal=getBalance(root);

    if(bal>1 && getBalance(root->left)>=0){
        printf("LL Rotation\n");
        return rightRotate(root);
    }
    if(bal>1 && getBalance(root->left)<0){
        printf("LR Rotation\n");
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    if(bal<-1 && getBalance(root->right)<=0){
        printf("RR Rotation\n");
        return leftRotate(root);
    }
    if(bal<-1 && getBalance(root->right)>0){
        printf("RL Rotation\n");
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }

    printf("NO Rotation\n");
    return root;
}

int main(){
    int n,x,d;
    struct node *root=NULL;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        root=insert(root,x);
    }

    scanf("%d",&d);
    root=deleteNode(root,d);

    if(root)
        printf("Height = %d\n",root->height);
    else
        printf("Height = 0\n");

    return 0;
}
