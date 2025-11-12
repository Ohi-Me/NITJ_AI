#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue1[MAX],queue2[MAX],mergedQueue[MAX];
int front1=0,rear1=-1,front2=0,rear2=-1,frontM=0,rearM=-1;

void enqueue(int queue[],int *rear,int val){
    queue[++(*rear)]=val;
}

int dequeue(int queue[],int *front){
    return queue[(*front)++];
}

int isEmpty(int front,int rear){
    return front>rear;
}

void display(int queue[],int front,int rear){
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

void mergeQueues(){
    while(!isEmpty(front1,rear1)&&!isEmpty(front2,rear2)){
        if(queue1[front1]<=queue2[front2]){
            enqueue(mergedQueue,&rearM,dequeue(queue1,&front1));
        }else{
            enqueue(mergedQueue,&rearM,dequeue(queue2,&front2));
        }
    }
    while(!isEmpty(front1,rear1)){
        enqueue(mergedQueue,&rearM,dequeue(queue1,&front1));
    }
    while(!isEmpty(front2,rear2)){
        enqueue(mergedQueue,&rearM,dequeue(queue2,&front2));
    }
}

int main(){
    int n1,n2,val;
    printf("Enter size of first queue: ");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        scanf("%d",&val);
        enqueue(queue1,&rear1,val);
    }
    printf("Enter size of second queue: ");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++){
        scanf("%d",&val);
        enqueue(queue2,&rear2,val);
    }
    mergeQueues();
    printf("Merged sorted queue: ");
    display(mergedQueue,frontM,rearM);
    return 0;
}
