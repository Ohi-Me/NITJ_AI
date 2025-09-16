#include <stdio.h>

int sum(int arr[],int n){
    if(n==0){
        return 0;
    }
    return arr[n-1]+sum(arr,n-1);
}

int main() {
	// your code goes here
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
	    int x;
	    scanf("%d",&arr[i]);
	}
	long long ans=sum(arr,n);
	printf("%ld",ans);
	return 0;
}

