#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Queue {
    int front, rear, size;
    struct Node** arr;
};

struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->arr = (struct Node**)malloc(capacity * sizeof(struct Node*));
    return q;
}

int isEmpty(struct Queue* q) {
    return q->size == 0;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->rear = (q->rear + 1);
    q->arr[q->rear] = node;
    q->size++;
}

struct Node* dequeue(struct Queue* q) {
    struct Node* node = q->arr[q->front];
    q->front = (q->front + 1);
    q->size--;
    return node;
}

void levelOrder(struct Node* root) {
    if (!root) return;
    struct Queue* q = createQueue(100);
    enqueue(q, root);
    while (!isEmpty(q)) {
        struct Node* node = dequeue(q);
        printf("%d ", node->data);
        if (node->left) enqueue(q, node->left);
        if (node->right) enqueue(q, node->right);
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    levelOrder(root);
    return 0;
}