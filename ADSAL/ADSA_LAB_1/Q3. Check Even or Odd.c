#include <stdio.h>

int main() {
	// your code goes here
	int x;
	scanf("%d",&x);
	printf("Enter the number to check even or odd: x : %d\n",x);
	if(x%2==0){
	    printf("The number %d is even",x);
    }
    else{
        printf("The number %d is Odd",x);
    }
    return 0;
}