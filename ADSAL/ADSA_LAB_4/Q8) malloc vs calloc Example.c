#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    int n, i;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student* arr1 = (struct Student*) malloc(n * sizeof(struct Student));
    printf("\nUsing malloc:\n");
    for(i = 0; i < n; i++) {
        printf("Student %d initial marks: %d\n", i+1, arr1[i].marks);
    }

    struct Student* arr2 = (struct Student*) calloc(n, sizeof(struct Student));
    printf("\nUsing calloc:\n");
    for(i = 0; i < n; i++) {
        printf("Student %d initial marks: %d\n", i+1, arr2[i].marks);
    }

    free(arr1);
    free(arr2);

    return 0;
}
