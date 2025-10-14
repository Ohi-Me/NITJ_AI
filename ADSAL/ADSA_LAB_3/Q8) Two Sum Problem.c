#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    long long target;
    scanf("%d %lld", &n, &target);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bool isit = false;
    int start = -1, end = -1;

    for(int i = 0; i < n; i++) {
        int check = target - arr[i];
        for(int j = 0; j < n; j++) {
            if(i != j && arr[j] == check) {
                start = i;
                end = j;
                isit = true;
                break;
            }
        }
        if(isit) {
            break;
        }
    }

    if(isit) {
        printf("The indices of elements are: %d , %d\n", start, end);
    } else {
        printf("No such pair exists.\n");
    }

    return 0;
}
