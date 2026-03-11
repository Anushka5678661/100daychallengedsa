#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int heap[MAX_SIZE];
int heapSize = 0;

int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int x) {
    if (heapSize == MAX_SIZE) return;
    heap[heapSize] = x;
    int i = heapSize;
    heapSize++;
    while (i != 0 && heap[parent(i)] > heap[i]) {
        swap(&heap[parent(i)], &heap[i]);
        i = parent(i);
    }
}

void heapify(int i) {
    int l = leftChild(i);
    int r = rightChild(i);
    int smallest = i;
    if (l < heapSize && heap[l] < heap[smallest]) smallest = l;
    if (r < heapSize && heap[r] < heap[smallest]) smallest = r;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

int extractMin() {
    if (heapSize <= 0) return -1;
    if (heapSize == 1) {
        heapSize--;
        return heap[0];
    }
    int root = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;
    heapify(0);
    return root;
}

int peek() {
    if (heapSize <= 0) return -1;
    return heap[0];
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char op[20];
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }
    return 0;
}