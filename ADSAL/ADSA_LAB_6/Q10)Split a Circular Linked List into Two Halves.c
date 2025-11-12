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

void display(struct node *h) {
    if (!h) {
        printf("List empty\n");
        return;
    }
    struct node *t = h;
    do {
        printf("%d ", t->data);
        t = t->next;
    } while (t != h);
    printf("\n");
}

void splitList(struct node *head, struct node **head1, struct node **head2) {
    if (!head || head->next == head) {
        *head1 = head;
        *head2 = NULL;
        return;
    }

    struct node *slow = head, *fast = head;

    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    *head1 = head;
    *head2 = slow->next;
    fast = (fast->next->next == head) ? fast->next : fast;
    fast->next = *head2;
    slow->next = *head1;
}

int main() {
    int n, x;
    struct node *head1 = NULL, *head2 = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &x);
        insertEnd(x);
    }

    printf("Original circular list: ");
    display(head);

    splitList(head, &head1, &head2);

    printf("First half: ");
    display(head1);

    printf("Second half: ");
    display(head2);

    return 0;
}
