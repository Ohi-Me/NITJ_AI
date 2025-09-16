#include <stdio.h>

int main() {
	// your code goes here
	char str[1000];
	scanf("%s",str);
	int n=strlen(str);
	int start=0;
	int end=n-1;
	while(start<end){
	    char temp=str[end];
	    str[end]=str[start];
	    str[start]=temp;
	    start--;
	    end++;
	}
	printf("%s",str);
	return 0;
}