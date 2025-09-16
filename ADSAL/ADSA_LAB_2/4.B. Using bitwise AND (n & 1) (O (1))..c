#include <stdio.h>
#include <string.h>


int main() {
	// your code goes here
	int n;
	scanf("%d",&n);
	if((n&1)==0){
	    printf("It is Even Number");
	}
	else{
	    printf("It is ODD Number");
	}
	return 0;
}