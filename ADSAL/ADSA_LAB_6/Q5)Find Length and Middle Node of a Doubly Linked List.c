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

int length() {
    int c = 0;
    struct node *t = head;
    while (t) {
        c++;
        t = t->next;
    }
    return c;
}

struct node* middle() {
    struct node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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

    printf("List: ");
    display();

    int len = length();
    printf("Length = %d\n", len);

    struct node *mid = middle();
    if (mid) printf("Middle node = %d\n", mid->data);

    return 0;
}
