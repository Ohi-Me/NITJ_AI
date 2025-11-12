#include <stdio.h>
#include <stdlib.h>

struct Item{int left;int right;int visited;};

void merge(int arr[],int temp[],int left,int mid,int right){
    int i=left,j=mid+1,k=left;
    while(i<=mid && j<=right){
        if(arr[i]<=arr[j]) temp[k++]=arr[i++];
        else temp[k++]=arr[j++];
    }
    while(i<=mid) temp[k++]=arr[i++];
    while(j<=right) temp[k++]=arr[j++];
    for(i=left;i<=right;i++) arr[i]=temp[i];
}

int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    if(n<=0){
        printf("Invalid size\n");
        return 0;
    }

    int *arr=malloc(n*sizeof(int));
    int *temp=malloc(n*sizeof(int));

    printf("Enter %d elements: ",n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    int stackSize=2*n+5;
    struct Item *stack=malloc(stackSize*sizeof(struct Item));
    int top=-1;
    stack[++top]=(struct Item){0,n-1,0};

    while(top>=0){
        struct Item cur=stack[top--];
        int L=cur.left;
        int R=cur.right;
        if(L>=R) continue;
        if(cur.visited==0){
            stack[++top]=(struct Item){L,R,1};
            int mid=(L+R)/2;
            stack[++top]=(struct Item){mid+1,R,0};
            stack[++top]=(struct Item){L,mid,0};
        }else{
            int mid=(L+R)/2;
            merge(arr,temp,L,mid,R);
        }
    }

    printf("Sorted array: ");
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    printf("\n");

    free(arr);
    free(temp);
    free(stack);
    return 0;
}
