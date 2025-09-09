#include <stdio.h>
#include <limits.h>

int main() {
    long long n;
    scanf("%lld", &n);
    printf("Give array size later input array elements, lets find Largest number you gave in aarray : %lld\n",n);
    long long ths[n];
    long long maxi=LLONG_MIN;
    for(int i=0;i<n;i++){
        scanf("%lld",&ths[i]);
        // maxi=max(maxi,ths[i]);
        if(ths[i]>maxi) {
            maxi=ths[i];
        }
    }
    // for(int i=0;i<n;i++){
    //     if(ths[i]>maxi) {
    //         maxi=ths[i];
    //     }
    // }
    
    printf("The Largest number in your given array is %lld\n",maxi);
    
    return 0;
}