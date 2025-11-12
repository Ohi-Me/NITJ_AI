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
        n->next = head;
        return;
    }
    struct node *t = head;
    while (t->next != head)
        t = t->next;
    t->next = n;
    n->next = head;
}

void insertAfter(int key, int x) {
    if (!head) return;
    struct node *t = head;
    do {
        if (t->data == key) {
            struct node *n = create(x);
            n->next = t->next;
            t->next = n;
            return;
        }
        t = t->next;
    } while (t != head);
    printf("Key not found\n");
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
    int n, x, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &x);
        insertEnd(x);
    }

    printf("Current list: ");
    display();

    printf("Enter key after which to insert: ");
    scanf("%d", &key);
    printf("Enter value to insert: ");
    scanf("%d", &x);
    insertAfter(key, x);

    printf("After insertion: ");
    display();

    return 0;
}
