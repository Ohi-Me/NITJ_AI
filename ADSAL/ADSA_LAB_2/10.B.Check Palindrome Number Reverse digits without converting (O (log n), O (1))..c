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
	int low=0;
	int high=strlen(str)-1;
	while(low<high){
	    char ch=str[high];
	    str[low]=str[high];
	    str[high]=ch;
	    low++;
	    high--;
	}
// 	int ans= atoi(str);
    int ans;
	sscanf(str, "%d", &ans);
	printf("The Reverse Number of given number %d is %d : ",n,ans);
	return 0;
}