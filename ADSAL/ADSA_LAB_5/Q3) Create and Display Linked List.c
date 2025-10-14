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
    int n, val;
    struct simple *head = NULL;

    printf("Enter the number of nodes:\n");
    scanf("%d", &n);

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

    return 0;
}
