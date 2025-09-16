#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main() {
	// your code goes here
	int n,m;
	scanf("%d%d",&n,&m);
	n=n^m;
	m=n^m;
	n=n^m;
	printf("The Swaps of number is %d and %d",n,m);
	return 0;
}