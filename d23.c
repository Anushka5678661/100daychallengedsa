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

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) return newNode;
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = (l1 != NULL) ? l1 : l2;
    return dummy.next;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(" ");
        head = head->next;
    }
}

int main() {
    int n, m, val;
    scanf("%d", &n);
    struct Node* list1 = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        list1 = insertEnd(list1, val);
    }
    scanf("%d", &m);
    struct Node* list2 = NULL;
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        list2 = insertEnd(list2, val);
    }
    struct Node* merged = mergeLists(list1, list2);
    printList(merged);
    return 0;
}