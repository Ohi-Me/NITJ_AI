#include <stdio.h>
#include <stdbool.h>
void natural(int n,int i){
    if(i>n){
        return;
    }
    printf("%d ",i);
    return natural(n,i+1);
}


int main() {
	// your code goes here
	int n;
	scanf("%d",&n);
	natural(n,1);
	return 0;
}