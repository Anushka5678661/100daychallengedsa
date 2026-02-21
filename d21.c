#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* createList(int n) {
    int value;
    struct Node *head = NULL, *temp = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        temp = createNode(value);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}

void traverseList(struct Node* head) {
    struct Node* current = head;
    printf("Output: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    struct Node* head = createList(n);
    traverseList(head);
    return 0;
}