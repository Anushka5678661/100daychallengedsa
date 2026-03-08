#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;
int size = 0;

void enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    if (front == NULL) {
        front = rear = temp;
        rear->next = front;
    } else {
        rear->next = temp;
        rear = temp;
        rear->next = front;
    }
    size++;
}

void rotate() {
    if (front == NULL) return;
    front = front->next;
    rear = rear->next;
}

void display() {
    if (front == NULL) return;
    struct Node* temp = front;
    int count = 0;
    do {
        printf("%d", temp->data);
        count++;
        if (count < size) printf(" ");
        temp = temp->next;
    } while (temp != front);
}

int main() {
    int n, m, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        rotate();
    }
    display();
    return 0;
}