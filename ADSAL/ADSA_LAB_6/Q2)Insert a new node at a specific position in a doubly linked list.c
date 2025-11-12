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

void insertPos(int x, int pos) {
    struct node *n = create(x);
    if (pos == 1) {
        n->next = head;
        if (head) head->prev = n;
        head = n;
        return;
    }
    struct node *t = head;
    for (int i = 1; i < pos - 1 && t; i++)
        t = t->next;
    if (!t) {
        printf("Invalid position\n");
        free(n);
        return;
    }
    n->next = t->next;
    n->prev = t;
    if (t->next) t->next->prev = n;
    t->next = n;
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
    int n, x, pos;
    printf("Enter number of insertions: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value and position: ");
        scanf("%d %d", &x, &pos);
        insertPos(x, pos);
        printf("List: ");
        display();
    }

    return 0;
}
