#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

void init(Deque* dq) {
    dq->front = 0;
    dq->rear = -1;
    dq->size = 0;
}

int empty(Deque* dq) {
    return dq->size == 0;
}

int full(Deque* dq) {
    return dq->size == MAX;
}

void push_front(Deque* dq, int x) {
    if (full(dq)) return;
    dq->front = (dq->front - 1 + MAX) % MAX;
    dq->arr[dq->front] = x;
    dq->size++;
}

void push_back(Deque* dq, int x) {
    if (full(dq)) return;
    dq->rear = (dq->rear + 1) % MAX;
    dq->arr[dq->rear] = x;
    dq->size++;
}

void pop_front(Deque* dq) {
    if (empty(dq)) return;
    dq->front = (dq->front + 1) % MAX;
    dq->size--;
}

void pop_back(Deque* dq) {
    if (empty(dq)) return;
    dq->rear = (dq->rear - 1 + MAX) % MAX;
    dq->size--;
}

int front(Deque* dq) {
    if (empty(dq)) return -1;
    return dq->arr[dq->front];
}

int back(Deque* dq) {
    if (empty(dq)) return -1;
    return dq->arr[dq->rear];
}

int size(Deque* dq) {
    return dq->size;
}

void clear(Deque* dq) {
    dq->front = 0;
    dq->rear = -1;
    dq->size = 0;
}

int main() {
    Deque dq;
    init(&dq);

    push_back(&dq, 10);
    push_front(&dq, 20);
    push_back(&dq, 30);

    printf("Front: %d\n", front(&dq));
    printf("Back: %d\n", back(&dq));
    printf("Size: %d\n", size(&dq));

    pop_front(&dq);
    pop_back(&dq);

    printf("Front after pops: %d\n", front(&dq));
    printf("Size after pops: %d\n", size(&dq));

    clear(&dq);
    printf("Empty after clear: %d\n", empty(&dq));

    return 0;
}