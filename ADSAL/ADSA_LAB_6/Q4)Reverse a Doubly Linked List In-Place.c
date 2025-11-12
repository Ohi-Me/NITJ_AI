#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

struct node* create(int x) {
    struct node *n = malloc(sizeof(struct node));
    n->data = x;
    n->prev = n->next = NULL;
    return n;
}

void insertEnd(int x) {
    struct node *n = create(x);
    if (!head) head = n;
    else {
        struct node *t = head;
        while (t->next) t = t->next;
        t->next = n;
        n->prev = t;
    }
}

void reverse() {
    struct node *t = head, *temp = NULL;
    if (!head) return;
    while (t) {
        temp = t->prev;
        t->prev = t->next;
        t->next = temp;
        t = t->prev;
    }
    if (temp) head = temp->prev;
}

void display() {
    struct node *t = head;
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    int n, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &x);
        insertEnd(x);
    }

    printf("Original list: ");
    display();

    reverse();

    printf("Reversed list: ");
    display();

    return 0;
}
