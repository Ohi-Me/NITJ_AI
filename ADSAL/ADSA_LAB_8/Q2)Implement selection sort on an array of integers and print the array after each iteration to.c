#include <stdio.h>

void selectionSort(int arr[],int n){
    int i,j,minIndex,temp;
    for(i=0;i<n-1;i++){
        minIndex=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
        printf("After iteration %d: ",i+1);
        for(j=0;j<n;j++){
            printf("%d ",arr[j]);
        }
        printf("\n");
    }
}

int main(){
    int n;
    printf("Enter size: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    selectionSort(arr,n);
    return 0;
}
