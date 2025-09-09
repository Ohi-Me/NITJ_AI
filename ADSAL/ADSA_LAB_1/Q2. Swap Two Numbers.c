#include <stdio.h>

int main() {
	// your code goes here
	int x,y;
	scanf("%d %d",&x,&y);
	printf("Enter two number: x : %d y : %d\n",x ,y);
	int temp=x;
	x=y;
	y=temp;
	printf("After swaping \n");
	printf("x = %d\n",x);
	printf("y = %d\n",y);
}