#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int val) {
    if (val == -1) return NULL;
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

typedef struct {
    Node* arr[100];
    int front, rear;
} Queue;

void enqueue(Queue *q, Node* node) {
    q->arr[++q->rear] = node;
}

Node* dequeue(Queue *q) {
    return q->arr[++q->front];
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    if (N == 0 || arr[0] == -1) return 0;

    Node* root = newNode(arr[0]);
    Queue q = {.front = -1, .rear = -1};
    enqueue(&q, root);

    int i = 1;
    while (i < N) {
        Node* parent = dequeue(&q);
        if (arr[i] != -1) {
            parent->left = newNode(arr[i]);
            enqueue(&q, parent->left);
        }
        i++;
        if (i < N && arr[i] != -1) {
            parent->right = newNode(arr[i]);
            enqueue(&q, parent->right);
        }
        i++;
    }

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    return 0;
}