#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);
    printf("Give number i will sum of all digit in number you gave: %lld\n",n);
    
    long long original=n;
    long long sum=0;
    long long count=0;
    
    while(n!=0){
        sum+=(n%10);
        n/=10;
    }
    printf("The Sum digit in number %lld is %lld\n",original,sum);

    return 0;
}