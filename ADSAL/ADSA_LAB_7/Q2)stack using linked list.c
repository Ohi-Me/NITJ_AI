#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *top=NULL;

void push(int x){
    struct node *n=malloc(sizeof(struct node));
    n->data=x;
    n->next=top;
    top=n;
}

void pop(){
    if(top==NULL){
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped element: %d\n",top->data);
    struct node *t=top;
    top=top->next;
    free(t);
}

void peek(){
    if(top==NULL){
        printf("Stack empty\n");
        return;
    }
    printf("Top element: %d\n",top->data);
}

void display(){
    if(top==NULL){
        printf("Stack empty\n");
        return;
    }
    struct node *t=top;
    printf("Stack elements: ");
    while(t){
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
}

int main(){
    int ch,val;
    while(1){
        printf("\n1.Push  2.Pop  3.Peek  4.Display  5.Exit\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter value: ");
                scanf("%d",&val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
