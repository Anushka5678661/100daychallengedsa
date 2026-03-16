#include <stdio.h>

typedef struct {
    int arr[100];
    int front, rear;
} Queue;

typedef struct {
    int arr[100];
    int top;
} Stack;

void enqueue(Queue *q, int val) {
    q->arr[++q->rear] = val;
}

int dequeue(Queue *q) {
    return q->arr[++q->front];
}

void push(Stack *s, int val) {
    s->arr[++s->top] = val;
}

int pop(Stack *s) {
    return s->arr[s->top--];
}

int main() {
    int N, i, val;
    scanf("%d", &N);

    Queue q = {.front = -1, .rear = -1};
    Stack s = {.top = -1};

    for (i = 0; i < N; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    while (q.front != q.rear) {
        push(&s, dequeue(&q));
    }

    while (s.top != -1) {
        enqueue(&q, pop(&s));
    }

    for (i = q.front + 1; i <= q.rear; i++) {
        printf("%d ", q.arr[i]);
    }

    return 0;
}