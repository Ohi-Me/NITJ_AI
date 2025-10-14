#include <stdio.h>
#include <string.h>

struct Book {
    char title[100];
    char author[50];
    float price;
};

int main() {
    int n;
    printf("Enter number of books: ");
    scanf("%d", &n);

    struct Book books[n];
    for(int i = 0; i < n; i++) {
        scanf(" %[^\n]", books[i].title);
        scanf(" %[^\n]", books[i].author);
        scanf("%f", &books[i].price);
    }

    float limit;
    printf("Enter price limit: ");
    scanf("%f", &limit);

    printf("\nBooks with price above %.2f:\n", limit);
    int found = 0;
    for(int i = 0; i < n; i++) {
        if(books[i].price > limit) {
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Price: %.2f\n\n", books[i].price);
            found = 1;
        }
    }
    if(!found) {
        printf("No books found above %.2f\n", limit);
    }

    return 0;
}
