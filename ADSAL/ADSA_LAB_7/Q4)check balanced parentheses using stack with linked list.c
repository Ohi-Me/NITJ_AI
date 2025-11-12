#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    struct node *next;
};

struct node *top=NULL;

void push(char c){
    struct node *n=malloc(sizeof(struct node));
    n->data=c;
    n->next=top;
    top=n;
}

char pop(){
    if(top==NULL)return '\0';
    char c=top->data;
    struct node *t=top;
    top=top->next;
    free(t);
    return c;
}

int main(){
    char exp[100];
    int flag=0;
    printf("Enter expression: ");
    scanf("%s",exp);
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
            push(exp[i]);
        else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
            char c=pop();
            if((exp[i]==')'&&c!='(')||(exp[i]=='}'&&c!='{')||(exp[i]==']'&&c!='[')){
                flag=1;
                break;
            }
        }
    }
    if(top!=NULL)flag=1;
    if(flag==0)printf("Balanced\n");
    else printf("Not Balanced\n");
    return 0;
}
