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

struct Node* concatenate(struct Node *head1, struct Node *head2) {
    if (head1 == NULL) {
        return head2;
    }
    struct Node *temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
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

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n1);

    for (int i = 0; i < n1; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        head1 = create(head1, val);
    }

    printf("Enter number of nodes in second list: ");
    scanf("%d", &n2);

    for (int i = 0; i < n2; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        head2 = create(head2, val);
    }

    printf("\nFirst Linked List: ");
    display(head1);

    printf("Second Linked List: ");
    display(head2);

    head1 = concatenate(head1, head2);

    printf("Concatenated Linked List: ");
    display(head1);

    return 0;
}
