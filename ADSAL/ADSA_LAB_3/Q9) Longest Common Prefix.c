#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);

    char arr[n][34];
    for(int i = 0; i < n; i++) {
        scanf(" %[^\n]", arr[i]);
    }

    char str[34] = "";
    char prev[34];
    strcpy(prev, arr[0]);
    int shortestStrLength = strlen(prev);

    for(int i = 0; i < shortestStrLength; i++) {
        char curr = prev[i];
        bool isit = true;
        for(int j = 1; j < n; j++) {
            if(arr[j][i] != curr) {
                isit = false;
                break;
            }
        }
        if(isit) {
            int len = strlen(str);
            str[len] = curr;
            str[len+1] = '\0';
        } else {
            break;
        }
    }

    if(strlen(str) > 0) {
        printf("%s\n", str);
    } else {
        printf("\n");
    }

    return 0;
}
