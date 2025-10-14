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

void display(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* deleteBeginning(struct Node *head) {
    if (head == NULL) return NULL;
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* deleteEnd(struct Node *head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

struct Node* deleteAtPosition(struct Node *head, int pos) {
    if (head == NULL) return NULL;
    if (pos == 0) {
        return deleteBeginning(head);
    }
    struct Node *temp = head;
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position!\n");
        return head;
    }
    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
    return head;
}

int main() {
    int n, val, pos;
    struct Node *head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &val);
        head = create(head, val);
    }

    printf("\nOriginal List: ");
    display(head);

    head = deleteBeginning(head);
    printf("After deleting from beginning: ");
    display(head);

    head = deleteEnd(head);
    printf("After deleting from end: ");
    display(head);

    printf("Enter position to delete (0-based): ");
    scanf("%d", &pos);
    head = deleteAtPosition(head, pos);
    printf("After deleting from position %d: ", pos);
    display(head);

    return 0;
}
