#include <stdio.h>
#include <string.h>


int main() {
	// your code goes here
	char str[1000];
	scanf("%s",str);
	int n=strlen(str);
	int end=n-1;
	char ans[1000];
	
	for(int i=end;i>=0;i--){
	    ans[end-i]=str[i];
	}
	printf("%s",ans);
	return 0;
}