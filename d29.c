#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* rotateRight(struct Node* head, int k, int n) {
    if (!head || k == 0 || k % n == 0) return head;

    struct Node* tail = head;
    while (tail->next) tail = tail->next;
    tail->next = head;

    int steps = n - (k % n);
    struct Node* newTail = head;
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    struct Node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, k;
    scanf("%d", &n);

    struct Node* head = NULL;
    struct Node* temp = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (!head) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k, n);
    printList(head);

    return 0;
}