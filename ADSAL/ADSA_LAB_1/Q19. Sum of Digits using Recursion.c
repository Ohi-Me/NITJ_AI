#include <stdio.h>

int sumOfDigits(int n) {
    if (n == 0)
        return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int num;
    printf("Enter a number to find the sum of its digits: \n");
    scanf("%d", &num);

    if (num < 0) {
        num = -num;
    }

    int sum = sumOfDigits(num);
    printf("The sum of digits of %d is: %d\n", num, sum);

    return 0;
}
