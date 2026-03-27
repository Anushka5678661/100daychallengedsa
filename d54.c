#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    Node* root = newNode(arr[0]);
    Node** queue = (Node**)malloc(n * sizeof(Node*));
    int front = 0, rear = 0, i = 1;
    queue[rear++] = root;
    while (front < rear && i < n) {
        Node* curr = queue[front++];
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        if (i >= n) break;
        if (arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    free(queue);
    return root;
}

void zigzagTraversal(Node* root) {
    if (!root) return;
    Node** queue = (Node**)malloc(1000 * sizeof(Node*));
    int front = 0, rear = 0;
    queue[rear++] = root;
    int leftToRight = 1;
    while (front < rear) {
        int size = rear - front;
        int* level = (int*)malloc(size * sizeof(int));
        for (int i = 0; i < size; i++) {
            Node* node = queue[front++];
            level[i] = node->val;
            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        if (leftToRight) {
            for (int i = 0; i < size; i++) printf("%d ", level[i]);
        } else {
            for (int i = size - 1; i >= 0; i--) printf("%d ", level[i]);
        }
        leftToRight = !leftToRight;
        free(level);
    }
    free(queue);
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    Node* root = buildTree(arr, N);
    zigzagTraversal(root);
    return 0;
}