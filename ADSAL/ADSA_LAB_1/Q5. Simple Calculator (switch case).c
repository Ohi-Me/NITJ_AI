#include <stdio.h>

int main() {
    double num1, num2;
    char op;

    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter second number: ");
    scanf("%lf", &num2);
    
    printf("Enter an operator (+, -, *, /): %lf, %lf\n",num1,num2);
    scanf(" %c", &op); 

    switch(op) {
        case '+':
            printf("Result = %.2lf\n", num1 + num2);
            break;
        case '-':
            printf("Result = %.2lf\n", num1 - num2);
            break;
        case '*':
            printf("Result = %.2lf\n", num1 * num2);
            break;
        case '/':
            if(num2 != 0)
                printf("Result = %.2lf\n", num1 / num2);
            else
                printf("Error! Division by zero not allowed.\n");
            break;
        default:
            printf("Invalid operator!\n");
    }

    return 0;
}