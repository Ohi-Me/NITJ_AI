#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("Enter number you want to reverse : %d\n",n);
    
    // string str=to_string(n);
    // reverse(str.begin(),str.end());
    // long long x=stoi(str);
    int original=n;
    int rem=0;
    int reversed=0;
    while (n != 0) {
        rem = n % 10;
        reversed = reversed * 10 + rem;
        n /= 10;
    }
    printf("Reversed number of %d is: %d\n", original, reversed);

    return 0;
}