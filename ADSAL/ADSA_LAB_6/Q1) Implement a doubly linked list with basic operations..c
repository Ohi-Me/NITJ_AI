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

void insertBeg(int x) {
    struct node *n = create(x);
    if (!head) head = n;
    else {
        n->next = head;
        head->prev = n;
        head = n;
    }
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

void deleteNode(int x) {
    struct node *t = head;
    while (t && t->data != x) t = t->next;
    if (!t) return;
    if (t->prev) t->prev->next = t->next;
    else head = t->next;
    if (t->next) t->next->prev = t->prev;
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
    int ch, x;
    while (1) {
        printf("\n1.Insert at Beginning\n2.Insert at End\n3.Delete Node\n4.Display\n5.Exit\nEnter choice: ");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Enter value: ");
            scanf("%d", &x);
            insertBeg(x);
        } else if (ch == 2) {
            printf("Enter value: ");
            scanf("%d", &x);
            insertEnd(x);
        } else if (ch == 3) {
            printf("Enter value to delete: ");
            scanf("%d", &x);
            deleteNode(x);
        } else if (ch == 4) display();
        else break;
    }
    return 0;
}
