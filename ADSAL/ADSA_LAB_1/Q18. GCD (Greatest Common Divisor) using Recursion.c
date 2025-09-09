#include <stdio.h>

int gcd(int n1,int n2){
    if(n2==0){
        return n1;
    }
    return gcd(n2, n1%n2);
}

int main() {
    int n1,n2;
    printf("Enter two number to calculate GCD \n");
    scanf("%d%d", &n1,&n2);
    if(n1==0 && n2==0){
        printf("The GCD of number is not possible\n");
        return 0;
    }
    
    printf("The GCD of number is : \n");
    int x=gcd(n1,n2);
    printf("%d",x);

    return 0;
}
