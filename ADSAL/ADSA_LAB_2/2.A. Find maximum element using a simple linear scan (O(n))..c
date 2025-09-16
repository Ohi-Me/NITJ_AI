#include <stdio.h>
#include <limits.h>

int main() {
	// your code goes here
	int n;
	scanf("%d",&n);
	int maxi=INT_MIN;
	for(int i=0;i<n;i++){
	    int x;
	    scanf("%d",&x);
	    if(x>maxi){
	        maxi=x;
	    }
	}
	printf("%ld",maxi);
	return 0;
}

