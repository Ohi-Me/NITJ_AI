#include <stdio.h>

int fact(long long x){
    if(x==0){
        return 1;
    }
    if(x==1){
        return 1;
    }
    return x*fact(x-1);
}

int main() {
	// your code goes here
	int x;
	scanf("%d",&x);
	printf("Enter number for factorial : x : %d\n",x);
	long long fac=1;
	fac=fact(x);
	
	if(x!=0){
	    printf("The factorial is  = %d\n",fac);
	}
	else{
	    printf("The factorial is  = %d\n",fac);
	}
}