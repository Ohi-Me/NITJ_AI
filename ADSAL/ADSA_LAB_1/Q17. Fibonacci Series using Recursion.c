#include <stdio.h>
#define long long int

int fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return fib(n-1)+fib(n-2);
}

int main() {
    int n;
    printf("Enter a number to calculate Fibonacci \n");
    scanf("%d", &n);
    if(n<0){
        printf("The Fibonacci of number is not possible as you gave negative number : %d\n", n);
        return 0;
    }
    
    printf("The Fibonacci of number is : \n");
    for(int i=0;i<n;i++){
        printf("%d ",fib(i));
    }

    return 0;
}
