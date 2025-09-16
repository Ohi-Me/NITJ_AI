#include <stdio.h>

int main() {
	// your code goes here
	int n;
	scanf("%d",&n);
	long long sum=0;
	for(int i=0;i<n;i++){
	    int x;
	    scanf("%d",&x);
	    sum+=x;
	}
	printf("%ld",sum);
	return 0;
}

