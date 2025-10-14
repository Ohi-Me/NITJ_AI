#include <stdio.h>

int main() {
    int n;
    long long k;
    scanf("%d %lld", &n, &k);

    long long arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    long long RotatedArr[n];
    int j = 0;
    for(int i = (n - k % n); i < n; i++) {
        RotatedArr[j++] = arr[i];
    }
    for(int i = 0; i < (n - k % n); i++) {
        RotatedArr[j++] = arr[i];
    }

    printf("The Rotated Array after k positions are : ");
    for(int i = 0; i < n; i++) {
        printf("%lld ", RotatedArr[i]);
    }
    printf("\n");

    return 0;
}
