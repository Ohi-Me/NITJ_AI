#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node* create(int x) {
    struct node *n = malloc(sizeof(struct node));
    n->data = x;
    n->next = NULL;
    return n;
}

void insertEnd(int x) {
    struct node *n = create(x);
    if (!head) {
        head = n;
        return;
    }
    struct node *t = head;
    while (t->next)
        t = t->next;
    t->next = n;
}

int isCircular() {
    if (!head) return 0;
    struct node *t = head->next;
    while (t && t != head)
        t = t->next;
    return (t == head);
}

void makeCircular() {
    if (!head) return;
    struct node *t = head;
    while (t->next)
        t = t->next;
    t->next = head;
}

void display(int limit) {
    struct node *t = head;
    int count = 0;
    while (t && count < limit) {
        printf("%d ", t->data);
        t = t->next;
        count++;
    }
    printf("\n");
}

int main() {
    int n, x, choice;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &x);
        insertEnd(x);
    }

    printf("List created.\n1.Check if circular\n2.Make circular and check again\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        if (isCircular()) printf("List is circular\n");
        else printf("List is not circular\n");
    } else if (choice == 2) {
        makeCircular();
        if (isCircular()) printf("List is circular\n");
        else printf("List is not circular\n");
    }

    return 0;
}
