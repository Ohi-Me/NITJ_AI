#include <stdio.h>
#include <string.h>

int fact(int n){
    if(n==0 || n==1){
        return 1;
    }
    return n*fact(n-1);
}


int main() {
	// your code goes here
	int n;
	scanf("%d",&n);
	int ans=fact(n);
	printf("%d ",ans);
	return 0;
}