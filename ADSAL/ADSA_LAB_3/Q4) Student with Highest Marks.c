#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];
    for(int i = 0; i < n; i++) {
        printf("Enter details of student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    int maxIndex = 0;
    for(int i = 1; i < n; i++) {
        if(students[i].marks > students[maxIndex].marks) {
            maxIndex = i;
        }
    }

    printf("\nStudent with highest marks:\n");
    printf("Name: %s\n", students[maxIndex].name);
    printf("Roll Number: %d\n", students[maxIndex].rollNumber);
    printf("Marks: %.2f\n", students[maxIndex].marks);

    return 0;
}
