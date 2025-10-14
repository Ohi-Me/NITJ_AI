#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    long long S;
    scanf("%d %lld", &n, &S);

    long long arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    bool isit = false;
    int ans[2];

    for(int i = 0; i < n; i++) {
        long long sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(sum == S) {
                isit = true;
                ans[0] = i;
                ans[1] = j;
                break;
            }
        }
        if(isit) {
            break;
        }
    }

    if(isit) {
        printf("Yes There is contiguous subarray whose sum equals to S\n");
        printf("The following starting and ending indices of subarray : %d %d\n", ans[0], ans[1]);
    } else {
        printf("No Such subarray found\n");
    }

    return 0;
}
