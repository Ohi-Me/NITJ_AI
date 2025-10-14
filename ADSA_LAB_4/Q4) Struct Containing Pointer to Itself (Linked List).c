#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, val;
    struct Node *head = NULL, *temp = NULL, *prev = NULL;

    printf("Enter number of nodes: \n");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: \n", i+1);
        scanf("%d", &val);
        temp->data = val;
        temp->next = NULL;

        if(head == NULL) {
            head = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;
    }

    temp = head;
    printf("Result of Nodes : ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    temp = head;
    while(temp != NULL) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }

    return 0;
}
