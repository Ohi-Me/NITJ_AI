#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int data[MAX],priority[MAX];
int size=0;

void enqueue(int val,int pr){
    if(size==MAX){
        printf("Queue Overflow\n");
        return;
    }
    int i=size-1;
    while(i>=0 && priority[i]<pr){
        data[i+1]=data[i];
        priority[i+1]=priority[i];
        i--;
    }
    data[i+1]=val;
    priority[i+1]=pr;
    size++;
}

void dequeue(){
    if(size==0){
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued element: %d (Priority %d)\n",data[0],priority[0]);
    for(int i=0;i<size-1;i++){
        data[i]=data[i+1];
        priority[i]=priority[i+1];
    }
    size--;
}

void display(){
    if(size==0){
        printf("Queue empty\n");
        return;
    }
    printf("Priority Queue: ");
    for(int i=0;i<size;i++)
        printf("[%d|%d] ",data[i],priority[i]);
    printf("\n");
}

int main(){
    int ch,val,pr;
    while(1){
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter value and priority: ");
                scanf("%d%d",&val,&pr);
                enqueue(val,pr);
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
