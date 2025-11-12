#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* createNode(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

void append(struct Node** head,int value){
    struct Node* newNode=createNode(value);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    struct Node* temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void display(struct Node* head){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

struct Node* mergeLists(struct Node* a,struct Node* b){
    if(a==NULL)return b;
    if(b==NULL)return a;
    struct Node* result=NULL;
    if(a->data<=b->data){
        result=a;
        result->next=mergeLists(a->next,b);
    }else{
        result=b;
        result->next=mergeLists(a,b->next);
    }
    return result;
}

int main(){
    struct Node* list1=NULL;
    struct Node* list2=NULL;
    int n1,n2,val;
    printf("Enter size of first list: ");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        scanf("%d",&val);
        append(&list1,val);
    }
    printf("Enter size of second list: ");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++){
        scanf("%d",&val);
        append(&list2,val);
    }
    printf("Merged sorted list: ");
    struct Node* merged=mergeLists(list1,list2);
    display(merged);
    return 0;
}
