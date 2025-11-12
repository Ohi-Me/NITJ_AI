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

void selectionSort(struct Node* head){
    struct Node* current=head;
    while(current!=NULL){
        struct Node* minNode=current;
        struct Node* nextNode=current->next;
        while(nextNode!=NULL){
            if(nextNode->data<minNode->data){
                minNode=nextNode;
            }
            nextNode=nextNode->next;
        }
        if(minNode!=current){
            int temp=current->data;
            current->data=minNode->data;
            minNode->data=temp;
        }
        display(head);
        current=current->next;
    }
}

int main(){
    struct Node* head=NULL;
    int n,value;
    printf("Enter size: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        append(&head,value);
    }
    printf("Sorting process:\n");
    selectionSort(head);
    printf("Sorted list: ");
    display(head);
    return 0;
}
