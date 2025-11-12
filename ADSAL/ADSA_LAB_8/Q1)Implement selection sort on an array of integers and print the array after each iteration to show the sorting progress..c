#include <stdio.h>

int main(){
    int n,i,j,minIndex,temp;
    printf("Enter size: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
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
    return 0;
}
