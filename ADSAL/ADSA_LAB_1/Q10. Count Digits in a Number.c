#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("Give number i will count how many digit in number: %d\n",n);
    
    int original=n;
    int count=0;
    if(n==0){
        count=1;
    }
    else{
        while(n>0){
            n/=10;
            count++;
        }
    }
    printf("The digit in number %d is %d\n",original,count);

    return 0;
}