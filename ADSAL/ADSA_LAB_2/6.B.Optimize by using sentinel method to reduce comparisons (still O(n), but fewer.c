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
	scanf("%d",&target);
	int start=0;
	int end=n-1;
	bool isit=false;
	while(start<=end){
	    if(arr[start]!=target){
	        isit=true;
	        start++;
	    }
	    else if(arr[end]!=target){
	        isit=true;
	        end--;
	    }
	    else{
	        start++;
	        end--;
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