#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("ATM checks if PIN entered forward = reverse give pin: %d\n",n);
    
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
    if(original==reversed){
        printf("PIN you entered is pallindrome of %d is %d\n", original,reversed);
    }
    else{
        printf("PIN you entered is not pallindrome as %d\n", original);
    }

    return 0;
}