#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void reverse(int arr[],int l,int r){
    while(l<r){
        swap(&arr[l],&arr[r]);
        l++;
        r--;
    }
}

int main(){
    int n,k;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
        
    scanf("%d",&k);
    k=k%n;

    reverse(arr,0,n-1);
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}