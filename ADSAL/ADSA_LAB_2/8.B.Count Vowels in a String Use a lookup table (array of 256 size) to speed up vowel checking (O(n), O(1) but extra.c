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
	bool isVowel[256] = {false};
    isVowel['a'] = true;
    isVowel['e'] = true;
    isVowel['i'] = true;
    isVowel['o'] = true;
    isVowel['u'] = true;
    isVowel['A'] = true;
    isVowel['E'] = true;
    isVowel['I'] = true;
    isVowel['O'] = true;
    isVowel['U'] = true;
	for(int i=0;i<n;i++){
	    if(isVowel[str[i]]){
	        count+=1;
	    }
	}
	printf("The vowels in string is %d ",count);
	return 0;
}