#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
char stack[MAX];
char queue[MAX];
int top=-1,front=-1,rear=-1;

void push(char c){
    if(top<MAX-1)
        stack[++top]=c;
}

char pop(){
    if(top>=0)
        return stack[top--];
    return '\0';
}

void enqueue(char c){
    if(rear<MAX-1){
        if(front==-1)front=0;
        queue[++rear]=c;
    }
}

char dequeue(){
    if(front!=-1 && front<=rear)
        return queue[front++];
    return '\0';
}

int main(){
    char str[100];
    printf("Enter string: ");
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++){
        push(str[i]);
        enqueue(str[i]);
    }
    int flag=0;
    for(int i=0;i<strlen(str);i++){
        if(pop()!=dequeue()){
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");
    return 0;
}
