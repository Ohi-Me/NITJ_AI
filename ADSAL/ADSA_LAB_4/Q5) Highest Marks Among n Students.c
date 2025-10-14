#include <stdio.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    int n, i, maxIndex = 0;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student students[n];
    for(i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i+1);
        printf("Enter Name: ");
        scanf("%s", students[i].name);
        printf("Enter Marks: ");
        scanf("%d", &students[i].marks);
    }

    for(i = 1; i < n; i++) {
        if(students[i].marks > students[maxIndex].marks) {
            maxIndex = i;
        }
    }

    printf("\nStudent with highest marks:\n");
    printf("Name: %s\n", students[maxIndex].name);
    printf("Marks: %d\n", students[maxIndex].marks);

    return 0;
}
