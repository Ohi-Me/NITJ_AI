#include <stdio.h>
#include <stdbool.h>


bool isit(long long n){
    if(n==0 || n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    for(int i=3;i*i<=n;i+=2){
        if(n%i){
            return 0;
        }
    }
    return 1;
}

int main() {
    long long n;
    scanf("%lld", &n);
    printf("Give number lets check it is prime or not : %lld\n",n);
    
    bool hmm=isit(n);
    if(!hmm){
        printf("The number %lld you gave is not prime\n",n);
    }
    else{
        printf("The number %lld you gave is prime\n",n);
    }

    return 0;
}