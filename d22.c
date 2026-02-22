#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* tail = NULL;

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &temp->data);
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}