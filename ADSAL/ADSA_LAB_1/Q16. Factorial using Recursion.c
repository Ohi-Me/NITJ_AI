#include <stdio.h>
#define long long int

int fac(int n){
    if(n==0 || n==1){
        return 1;
    }
    return n*fac(n-1);
}

int main() {
    int x;
    printf("Enter a number to calculate Factorial \n");
    scanf("%d", &x);
    if(x<0){
        printf("The Factorial of number is not possible as you gave negative number : %d\n", x);
        return 0;
    }
    int fact=fac(x);
    printf("The Factorial of number %d is : %d\n", x,fact);

    return 0;
}
