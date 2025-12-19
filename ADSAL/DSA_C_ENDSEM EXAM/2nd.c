#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,k;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    scanf("%d",&k);
    int count=0;

    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==k){
                count++;
            }
        }
    }
    printf("%d",count);
    return 0;
}
