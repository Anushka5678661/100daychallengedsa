#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

typedef struct Queue {
    Node *node;
    int hd;
    struct Queue *next;
} Queue;

Node* newNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

void enqueue(Queue **front, Queue **rear, Node *node, int hd) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->node = node;
    q->hd = hd;
    q->next = NULL;
    if (*rear) (*rear)->next = q;
    else *front = q;
    *rear = q;
}

Queue* dequeue(Queue **front, Queue **rear) {
    if (!*front) return NULL;
    Queue *temp = *front;
    *front = (*front)->next;
    if (!*front) *rear = NULL;
    return temp;
}

Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    Node *root = newNode(arr[0]);
    Queue *front = NULL, *rear = NULL;
    enqueue(&front, &rear, root, 0);
    int i = 1;
    while (front && i < n) {
        Queue *q = dequeue(&front, &rear);
        Node *curr = q->node;
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(&front, &rear, curr->left, 0);
        }
        i++;
        if (i >= n) break;
        if (arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(&front, &rear, curr->right, 0);
        }
        i++;
        free(q);
    }
    return root;
}

typedef struct Map {
    int hd;
    int vals[100];
    int count;
    struct Map *next;
} Map;

Map* findOrCreate(Map **head, int hd) {
    Map *curr = *head;
    while (curr) {
        if (curr->hd == hd) return curr;
        curr = curr->next;
    }
    Map *m = (Map*)malloc(sizeof(Map));
    m->hd = hd;
    m->count = 0;
    m->next = *head;
    *head = m;
    return m;
}

void verticalOrder(Node *root) {
    if (!root) return;
    Queue *front = NULL, *rear = NULL;
    enqueue(&front, &rear, root, 0);
    Map *head = NULL;
    while (front) {
        Queue *q = dequeue(&front, &rear);
        Node *node = q->node;
        int hd = q->hd;
        Map *m = findOrCreate(&head, hd);
        m->vals[m->count++] = node->val;
        if (node->left) enqueue(&front, &rear, node->left, hd - 1);
        if (node->right) enqueue(&front, &rear, node->right, hd + 1);
        free(q);
    }
    int min = 1e9, max = -1e9;
    Map *curr = head;
    while (curr) {
        if (curr->hd < min) min = curr->hd;
        if (curr->hd > max) max = curr->hd;
        curr = curr->next;
    }
    for (int i = min; i <= max; i++) {
        curr = head;
        while (curr) {
            if (curr->hd == i) {
                for (int j = 0; j < curr->count; j++)
                    printf("%d ", curr->vals[j]);
                printf("\n");
                break;
            }
            curr = curr->next;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    Node *root = buildTree(arr, N);
    verticalOrder(root);
    return 0;
}