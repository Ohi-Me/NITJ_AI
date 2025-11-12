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

void insertBeg(int x) {
    struct node *n = create(x);
    if (!head) {
        head = n;
        n->next = head;
        return;
    }
    struct node *t = head;
    while (t->next != head)
        t = t->next;
    n->next = head;
    t->next = n;
    head = n;
}

void insertEnd(int x) {
    struct node *n = create(x);
    if (!head) {
        head = n;
        n->next = head;
        return;
    }
    struct node *t = head;
    while (t->next != head)
        t = t->next;
    t->next = n;
    n->next = head;
}

void display() {
    if (!head) {
        printf("List empty\n");
        return;
    }
    struct node *t = head;
    do {
        printf("%d ", t->data);
        t = t->next;
    } while (t != head);
    printf("\n");
}

int main() {
    int ch, x;
    while (1) {
        printf("\n1.Insert at Beginning\n2.Insert at End\n3.Display\n4.Exit\nEnter choice: ");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Enter value: ");
            scanf("%d", &x);
            insertBeg(x);
        } else if (ch == 2) {
            printf("Enter value: ");
            scanf("%d", &x);
            insertEnd(x);
        } else if (ch == 3) display();
        else break;
    }
    return 0;
}
