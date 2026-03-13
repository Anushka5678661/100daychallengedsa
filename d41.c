#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(struct Queue* q) {
    if (q->front == NULL)
        return -1;
    struct Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return value;
}

int main() {
    int N;
    scanf("%d", &N);
    struct Queue* q = createQueue();
    char op[10];
    int val;
    for (int i = 0; i < N; i++) {
        scanf("%s", op);
        if (strcmp(op, "ENQUEUE") == 0) {
            scanf("%d", &val);
            enqueue(q, val);
        } else if (strcmp(op, "DEQUEUE") == 0) {
            int res = dequeue(q);
            printf("%d\n", res);
        }
    }
    return 0;
}