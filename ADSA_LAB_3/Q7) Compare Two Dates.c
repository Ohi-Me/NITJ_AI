#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

int main() {
    struct Date d1, d2;

    printf("Enter first date (day month year): ");
    scanf("%d %d %d", &d1.day, &d1.month, &d1.year);

    printf("Enter second date (day month year): ");
    scanf("%d %d %d", &d2.day, &d2.month, &d2.year);

    printf("\nFirst Date: %02d-%02d-%04d", d1.day, d1.month, d1.year);
    printf("\nSecond Date: %02d-%02d-%04d\n", d2.day, d2.month, d2.year);

    if(d1.year < d2.year || (d1.year == d2.year && d1.month < d2.month) ||
       (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day)) {
        printf("\nThe earlier date is: %02d-%02d-%04d\n", d1.day, d1.month, d1.year);
    } else if(d1.year == d2.year && d1.month == d2.month && d1.day == d2.day) {
        printf("\nBoth dates are the same.\n");
    } else {
        printf("The earlier date is: %02d-%02d-%04d\n", d2.day, d2.month, d2.year);
    }

    return 0;
}
