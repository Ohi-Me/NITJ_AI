#include <stdio.h>

void selectionSort(int arr[],int start,int end){
    int i,j,minIndex,temp;
    for(i=start;i<end-1;i++){
        minIndex=i;
        for(j=i+1;j<end;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
}

void merge(int arr[],int temp[],int left,int mid,int right){
    int i=left,j=mid,k=left;
    while(i<mid && j<=right){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
        }
    }
    while(i<mid){
        temp[k++]=arr[i++];
    }
    while(j<=right){
        temp[k++]=arr[j++];
    }
    for(i=left;i<=right;i++){
        arr[i]=temp[i];
    }
}

int main(){
    int n,chunkSize;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n],temp[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter chunk size: ");
    scanf("%d",&chunkSize);
    for(int i=0;i<n;i+=chunkSize){
        int end=i+chunkSize;
        if(end>n)end=n;
        selectionSort(arr,i,end);
    }
    for(int size=chunkSize;size<n;size*=2){
        for(int left=0;left<n-size;left+=2*size){
            int mid=left+size;
            int right=left+2*size-1;
            if(right>=n)right=n-1;
            merge(arr,temp,left,mid,right);
        }
    }
    printf("Final merged sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
