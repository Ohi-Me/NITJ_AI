#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int queue[MAX];
int front=-1,rear=-1;

void enqueue(int x){
    if(rear==MAX-1){
        printf("Queue Overflow\n");
        return;
    }
    if(front==-1)front=0;
    queue[++rear]=x;
}

void dequeue(){
    if(front==-1||front>rear){
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued element: %d\n",queue[front++]);
}

void display(){
    if(front==-1||front>rear){
        printf("Queue empty\n");
        return;
    }
    printf("Queue elements: ");
    for(int i=front;i<=rear;i++)
        printf("%d ",queue[i]);
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
