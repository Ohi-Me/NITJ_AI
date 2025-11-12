#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front=NULL,*rear=NULL;

void enqueue(int x){
    struct node *n=malloc(sizeof(struct node));
    n->data=x;
    n->next=NULL;
    if(rear==NULL){
        front=rear=n;
        return;
    }
    rear->next=n;
    rear=n;
}

void dequeue(){
    if(front==NULL){
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued element: %d\n",front->data);
    struct node *t=front;
    front=front->next;
    if(front==NULL)rear=NULL;
    free(t);
}

void display(){
    if(front==NULL){
        printf("Queue empty\n");
        return;
    }
    struct node *t=front;
    printf("Queue elements: ");
    while(t){
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
}

int main(){
    int ch,val;
    while(1){
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter value: ");
                scanf("%d",&val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
