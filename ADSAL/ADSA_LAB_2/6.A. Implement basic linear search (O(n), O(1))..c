#include <stdio.h>
#include <stdbool.h>


int main() {
	// your code goes here
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
	    int x;
	    scanf("%d",&arr[i]);
	}
	int target;
	bool isit=false;
	scanf("%d",&target);
	
	for(int i=0;i<n;i++){
	    if(arr[i]==target){
	        isit=true;
	        break;
	    }
	}
	if(isit){
	    printf("The target value is in array");
	}
	else{
	    printf("The target value is NOT in array");
	}
	return 0;
}