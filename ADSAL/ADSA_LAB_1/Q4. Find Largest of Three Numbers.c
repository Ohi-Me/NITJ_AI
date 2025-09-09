#include <stdio.h>

int main() {
	// your code goes here
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	printf("Enter three number to check which is larger: x : %d\n",x);
	if(x==y && x==z){
	    printf("The number %d is equal as other two",x);
    }
	else if(x>=y && x>=z){
	    printf("The number %d is larger than other two",x);
    }
    else if(y>=x && y>=z){
        printf("The number %d is larger than other two",x);
    }
    else if(z>=x && z>=y){
        printf("The number %d is larger than other two",x);
    }
    return 0;
}