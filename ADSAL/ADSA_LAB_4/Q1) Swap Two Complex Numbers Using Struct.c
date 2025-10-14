#include <stdio.h>

struct complex {
    float real;
    float img;
};

int main() {
    struct complex num1, num2;
    printf("Complex number to swap\n");
    printf("Enter 1st Complex number First Real part then Imaginary part\n");
    scanf("%f %f", &num1.real, &num1.img);
    printf("Num1: %.2f + %.2fi\n", num1.real, num1.img);

    printf("Enter 2nd Complex number First Real part then Imaginary part\n");
    scanf("%f %f", &num2.real, &num2.img);
    printf("Num2: %.2f + %.2fi\n", num2.real, num2.img);

    float tempR = num1.real;
    num1.real = num2.real;
    num2.real = tempR;

    float tempI = num1.img;
    num1.img = num2.img;
    num2.img = tempI;

    printf("After Swapping : \n");
    printf("Num1: %.2f + %.2fi\n", num1.real, num1.img);
    printf("Num2: %.2f + %.2fi\n", num2.real, num2.img);

    return 0;
}
