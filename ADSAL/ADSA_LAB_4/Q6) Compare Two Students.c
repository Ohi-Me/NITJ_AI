#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int marks;
};

int main() {
    struct Student s1, s2;
    printf("Lets Compare Marks Between Two Students \n");
    printf("Enter name and marks of student 1 & student 2: ");
    scanf("%s %d", s1.name, &s1.marks);
    scanf("%s %d", s2.name, &s2.marks);

    if(strcmp(s1.name, s2.name) == 0 && s1.marks == s2.marks) {
        printf("The two students are equal.\n");
    } else {
        printf("The two students are not equal.\n");
    }

    return 0;
}
