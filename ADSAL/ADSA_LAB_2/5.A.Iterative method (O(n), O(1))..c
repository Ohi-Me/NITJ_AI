#include <stdio.h>
#include <string.h>


int main() {
	// your code goes here
	int n;
	scanf("%d",&n);
	long long ans=1;
	for(int i=1;i<=n;i++){
	    ans*=i;
	}
	printf("%lld ",ans);
	return 0;
}