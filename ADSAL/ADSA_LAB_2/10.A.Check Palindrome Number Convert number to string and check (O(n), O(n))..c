#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main() {
	// your code goes here
	int n;
	scanf("%d",&n);
	char str[20];
    sprintf(str, "%d", n);
	bool isit=true;
	int low=0;
	int high=strlen(str)-1;
	while(low<high){
	    if(str[low]!=str[high]){
	        isit=false;
	        break;
	    }
	    low++;
	    high--;
	}
	if(isit){
	    printf("Yes the number is Palindrome Number");
	}
	else{
	    printf("No the number is Palindrome Number");
	}
	return 0;
}