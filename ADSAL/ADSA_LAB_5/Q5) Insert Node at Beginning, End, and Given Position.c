#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* create(struct Node *head, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

struct Node* merge(struct Node *l1, struct Node *l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct Node *result = NULL;
    if (l1->data <= l2->data) {
        result = l1;
        result->next = merge(l1->next, l2);
    } else {
        result = l2;
        result->next = merge(l1, l2->next);
    }
    return result;
}

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    int n1, n2, val;
    struct Node *head1 = NULL, *head2 = NULL;

    printf("Enter number of nodes in first sorted list: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        head1 = create(head1, val);
    }

    printf("Enter number of nodes in second sorted list: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        head2 = create(head2, val);
    }

    printf("\nFirst List: ");
    display(head1);
    printf("Second List: ");
    display(head2);

    struct Node *merged = merge(head1, head2);
    printf("Merged Sorted List: ");
    display(merged);

    return 0;
}
