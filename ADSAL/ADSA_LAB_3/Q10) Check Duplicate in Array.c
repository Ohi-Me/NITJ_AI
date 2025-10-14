#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bool isit = false;
    int count = 0;

    for(int i = 0; i < n; i++) {
        int num = arr[i];
        for(int j = 0; j < n; j++) {
            if(i != j && num == arr[j]) {
                count++;
            }
            if(count > 0) {
                isit = true;
                break;
            }
        }
        count = 0;
        if(isit) {
            break;
        }
    }

    if(isit) {
        printf("TRUE\n");
    } else
