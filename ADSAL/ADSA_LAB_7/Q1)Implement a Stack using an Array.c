#include <stdio.h>
#include <stdlib.h>

#define MAX 5
int stack[MAX];
int top=-1;

void push(int x){
    if(top==MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=x;
}

void pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped element: %d\n",stack[top--]);
}

void display(){
    if(top==-1){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for(int i=top;i>=0;i--)
        printf("%d ",stack[i]);
    printf("\n");
}

int main(){
    int ch,val;
    while(1){
        printf("\n1.Push  2.Pop  3.Display  4.Exit\nEnter choice: ");
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
