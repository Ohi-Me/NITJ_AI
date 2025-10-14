#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    int n, new_n, i;
    printf("Enter initial number of students: ");
    scanf("%d", &n);

    struct Student* students = (struct Student*) malloc(n * sizeof(struct Student));
    for(i = 0; i < n; i++) {
        printf("\nEnter name and marks of student %d: ", i+1);
        scanf("%s %d", students[i].name, &students[i].marks);
    }

    printf("\nEnter number of new students to add: ");
    scanf("%d", &new_n);

    n += new_n;
    students = (struct Student*) realloc(students, n * sizeof(struct Student));

    for(i = n - new_n; i < n; i++) {
        printf("\nEnter name and marks of new student %d: ", i - (n - new_n) + 1);
        scanf("%s %d", students[i].name, &students[i].marks);
    }

    printf("\nAll students:\n");
    for(i = 0; i < n; i++) {
        printf("Student %d: %s, Marks: %d\n", i+1, students[i].name, students[i].marks);
    }

    free(students);
    return 0;
}
