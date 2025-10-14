#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    long long x;
    long long max = LLONG_MIN;
    long long secondmax = LLONG_MIN;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &x);
        if(x > max) {
            secondmax = max;
            max = x;
        } else if(x > secondmax && x != max) {
            secondmax = x;
        }
    }
    printf("The Second maximum element in array is : %lld\n", secondmax);
    return 0;
}
