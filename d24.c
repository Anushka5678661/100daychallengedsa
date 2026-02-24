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

struct Node* deleteKey(struct Node* head, int key) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    while (temp != NULL) {
        if (temp->data == key) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(" ");
        head = head->next;
    }
}

int main() {
    int n, val, key;
    scanf("%d", &n);
    struct Node* list = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        list = insertEnd(list, val);
    }
    scanf("%d", &key);
    list = deleteKey(list, key);
    printList(list);
    return 0;
}