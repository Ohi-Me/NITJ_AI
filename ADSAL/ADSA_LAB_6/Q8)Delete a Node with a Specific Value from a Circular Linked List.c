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

void deleteVal(int x) {
    if (!head) {
        printf("List empty\n");
        return;
    }
    struct node *curr = head, *prev = NULL;

    // If only one node
    if (head->next == head && head->data == x) {
        free(head);
        head = NULL;
        return;
    }

    // If head node is to be deleted
    if (head->data == x) {
        struct node *t = head;
        while (t->next != head)
            t = t->next;
        t->next = head->next;
        struct node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    // Search and delete
    do {
        if (curr->data == x) {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    printf("Value not found\n");
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
