#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    int n, i;
    scanf("%d", &n);
    printf("Enter number of employees: %d", n);

    struct Employee emp[n];
    for(i = 0; i < n; i++) {
        printf("\nEnter details of Employee %d\n", i+1);
        printf("Enter ID: ");
        scanf("%d", &emp[i].id);
        printf("Enter Name: ");
        scanf("%s", emp[i].name);
        printf("Enter Salary: ");
        scanf("%f", &emp[i].salary);
    }

    printf("\nAfter storing, Employee Information is:\n");
    for(i = 0; i < n; i++) {
        printf("\nEmployee %d\n", i+1);
        printf("ID: %d\n", emp[i].id);
        printf("Name: %s\n", emp[i].name);
        printf("Salary: %.2f\n", emp[i].salary);
    }

    return 0;
}
