#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char *str = NULL;
    size_t size = 0;
    int count = 0;

    printf("Enter a string, lets check how many vowel in it\n");
    ssize_t len = getline(&str, &size, stdin);

    if (len != -1) {
        for (ssize_t i = 0; i < len; i++) {
            char ch = tolower(str[i]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                count++;
            }
        }
    }
    printf("The given string has %d vowels in it\n", count);
    return 0;
}
