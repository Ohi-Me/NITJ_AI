#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front=NULL,*rear=NULL;

void enqueue(int x){
    struct node *t=(struct node*)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    if(!rear){
        front=rear=t;
        return;
    }
    rear->next=t;
    rear=t;
}

void reverseK(int k){
    struct node *cur=front,*prev=NULL,*next=NULL;
    struct node *tail=front;
    int c=0;

    while(cur && c<k){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
        c++;
    }

    if(tail) tail->next=cur;
    front=prev;

    if(!cur) rear=tail;
}

void display(){
    struct node *t=front;
    while(t){
        printf("%d ",t->data);
        t=t->next;
    }
}

int main(){
    int n,x,k;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        enqueue(x);
    }

    scanf("%d",&k);
    reverseK(k);
    display();

    return 0;
}
