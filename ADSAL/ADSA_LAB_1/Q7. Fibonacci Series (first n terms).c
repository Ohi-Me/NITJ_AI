#include <stdio.h>

int main() {
    int n, i;
    long long t1 = 0, t2 = 1, nextTerm;

    scanf("%d", &n);
    printf("Enter till number you want Fibonacci : %d\n",n);

    printf("Fibonacci Series: ");
    for (i = 1; i <= n; i++) {
        printf("%lld ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");

    return 0;
}