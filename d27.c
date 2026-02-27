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

struct Node* createList(int n) {
    int val;
    struct Node* head = NULL, *temp = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return head;
}

struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    while (head1 && head2) {
        if (head1->data == head2->data) return head1;
        head1 = head1->next;
        head2 = head2->next;
    }
    return NULL;
}

int main() {
    int n, m;
    scanf("%d", &n);
    struct Node* head1 = createList(n);
    scanf("%d", &m);
    struct Node* head2 = createList(m);

    struct Node* intersection = getIntersection(head1, head2);
    if (intersection) printf("%d\n", intersection->data);
    else printf("No Intersection\n");

    return 0;
}