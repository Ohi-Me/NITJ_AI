#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main() {
	// your code goes here
	char str[1000];
	scanf("%s",str);
	int count=0;
	int n=strlen(str);
	for(int i=0;i<n;i++){
	    char ch=tolower(str[i]);
	   // ch=ch.tolower(ch);
	    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'){
	        count+=1;
	    }
	}
	printf("The vowels in string is %d ",count);
	return 0;
}