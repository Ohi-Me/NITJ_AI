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

void deleteVal(int x) {
    struct node *t = head;
    while (t && t->data != x)
        t = t->next;
    if (!t) {
        printf("Value not found\n");
        return;
    }
    if (t->prev)
        t->prev->next = t->next;
    else
        head = t->next;
    if (t->next)
        t->next->prev = t->prev;
    free(t);
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
    int n, x, del;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &x);
        insertEnd(x);
    }

    printf("Current list: ");
    display();

    printf("Enter value to delete: ");
    scanf("%d", &del);
    deleteVal(del);

    printf("After deletion: ");
    display();

    return 0;
}
