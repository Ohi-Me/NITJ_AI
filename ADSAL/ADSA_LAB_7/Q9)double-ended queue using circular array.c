#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int deque[MAX];
int front=-1,rear=-1;

int isFull(){
    return((front==0 && rear==MAX-1)||(front==rear+1));
}

int isEmpty(){
    return(front==-1);
}

void insertFront(int x){
    if(isFull()){
        printf("Deque Overflow\n");
        return;
    }
    if(front==-1)
        front=rear=0;
    else if(front==0)
        front=MAX-1;
    else
        front--;
    deque[front]=x;
}

void insertRear(int x){
    if(isFull()){
        printf("Deque Overflow\n");
        return;
    }
    if(front==-1)
        front=rear=0;
    else if(rear==MAX-1)
        rear=0;
    else
        rear++;
    deque[rear]=x;
}

void deleteFront(){
    if(isEmpty()){
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted element: %d\n",deque[front]);
    if(front==rear)
        front=rear=-1;
    else if(front==MAX-1)
        front=0;
    else
        front++;
}

void deleteRear(){
    if(isEmpty()){
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted element: %d\n",deque[rear]);
    if(front==rear)
        front=rear=-1;
    else if(rear==0)
        rear=MAX-1;
    else
        rear--;
}

void display(){
    if(isEmpty()){
        printf("Deque empty\n");
        return;
    }
    printf("Deque elements: ");
    int i=front;
    while(1){
        printf("%d ",deque[i]);
        if(i==rear)break;
        i=(i+1)%MAX;
    }
    printf("\n");
}

int main(){
    int ch,val;
    while(1){
        printf("\n1.InsertFront  2.InsertRear  3.DeleteFront  4.DeleteRear  5.Display  6.Exit\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter value: ");
                scanf("%d",&val);
                insertFront(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d",&val);
                insertRear(val);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
