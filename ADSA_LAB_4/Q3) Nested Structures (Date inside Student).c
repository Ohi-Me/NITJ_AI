#include <stdio.h>

struct Address {
    char city[50];
    int pincode;
};

struct Student {
    char name[50];
    int class;
    struct Address addr;
};

int main() {
    int n, i;
    printf("Enter number of Students: ");
    scanf("%d", &n);

    struct Student Std[n];
    for(i = 0; i < n; i++) {
        printf("\nEnter details of Student %d\n", i+1);
        printf("Enter Name: ");
        scanf("%s", Std[i].name);
        printf("Enter Class: ");
        scanf("%d", &Std[i].class);
        printf("Enter City: ");
        scanf("%s", Std[i].addr.city);
        printf("Enter Pincode: ");
        scanf("%d", &Std[i].addr.pincode);
    }

    printf("\nStudents Information is:\n");
    for(i = 0; i < n; i++) {
        printf("\nStudent %d\n", i+1);
        printf("Name: %s\n", Std[i].name);
        printf("Class: %d\n", Std[i].class);
        printf("City: %s\n", Std[i].addr.city);
        printf("Pincode: %d\n", Std[i].addr.pincode);
    }

    return 0;
}
