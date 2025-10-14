#include <stdio.h>
#include <stdlib.h>

struct simple {
    int x;
    struct simple *next;
};

struct simple* createL(struct simple *head, int x) {
    struct simple *newNode = (struct simple*)malloc(sizeof(struct simple));
    newNode->x = x;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct simple *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

int main() {
    int n, val, element;
    struct simple *head = NULL;

    printf("Enter the number of nodes:\n");
    scanf("%d", &n);
    printf("Enter the Element to find in Linked List:\n");
    scanf("%d", &element);

    for (int i = 0; i < n; i++) {
        printf("Enter the value %d:\n", (i + 1));
        scanf("%d", &val);
        head = createL(head, val);
    }

    printf("Existing Linked List :- \n");
    struct simple *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->x);
        temp = temp->next;
    }
    printf("NULL\n");

    temp = head;
    int pos = 0, found = 0;
    while (temp != NULL) {
        if (temp->x == element) {
            printf("We got Element %d at position %d in Linked List\n", element, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }
    if (!found) {
        printf("Element %d not found in Linked List\n", element);
    }

    return 0;
}
