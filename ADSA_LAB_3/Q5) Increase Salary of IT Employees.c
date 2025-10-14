#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float salary;
    char department[20];
};

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee employe[n];
    for(int i = 0; i < n; i++) {
        printf("Enter details of Employee %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &employe[i].id);
        printf("Name: ");
        scanf(" %[^\n]s", employe[i].name);
        printf("Salary: ");
        scanf("%f", &employe[i].salary);
        printf("Department: ");
        scanf(" %[^\n]s", employe[i].department);
    }

    for(int i = 0; i < n; i++) {
        if(strcmp(employe[i].department, "IT") == 0) {
            employe[i].salary *= 1.10;
        }
    }

    printf("\nEmployee details after salary update:\n");
    for(int i = 0; i < n; i++) {
        printf("ID: %d\n", employe[i].id);
        printf("Name: %s\n", employe[i].name);
        printf("Salary: %.2f\n", employe[i].salary);
        printf("Department: %s\n\n", employe[i].department);
    }

    return 0;
}
