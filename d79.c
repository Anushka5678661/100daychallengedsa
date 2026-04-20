#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

// Structure for adjacency list node
typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

// Adjacency list
Node* adj[MAX];

// Min-heap node
typedef struct {
    int vertex;
    int dist;
} HeapNode;

// Min-heap
typedef struct {
    HeapNode* arr[MAX];
    int size;
} MinHeap;

// Function to create new adjacency node
Node* newNode(int v, int w) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->vertex = v;
    temp->weight = w;
    temp->next = NULL;
    return temp;
}

// Heap utility functions
void swap(HeapNode** a, HeapNode** b) {
    HeapNode* t = *a;
    *a = *b;
    *b = t;
}

void heapify(MinHeap* heap, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < heap->size && heap->arr[l]->dist < heap->arr[smallest]->dist)
        smallest = l;
    if (r < heap->size && heap->arr[r]->dist < heap->arr[smallest]->dist)
        smallest = r;

    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapify(heap, smallest);
    }
}

HeapNode* extractMin(MinHeap* heap) {
    if (heap->size == 0) return NULL;
    HeapNode* root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return root;
}

void insertHeap(MinHeap* heap, int v, int dist) {
    HeapNode* node = (HeapNode*)malloc(sizeof(HeapNode));
    node->vertex = v;
    node->dist = dist;
    int i = heap->size++;
    heap->arr[i] = node;
    while (i && heap->arr[(i-1)/2]->dist > heap->arr[i]->dist) {
        swap(&heap->arr[i], &heap->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Dijkstra’s Algorithm
void dijkstra(int n, int source) {
    int dist[MAX];
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[source] = 0;

    MinHeap heap;
    heap.size = 0;
    insertHeap(&heap, source, 0);

    while (heap.size > 0) {
        HeapNode* minNode = extractMin(&heap);
        int u = minNode->vertex;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->vertex;
            int w = temp->weight;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                insertHeap(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print distances
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize adjacency list
    for (int i = 1; i <= n; i++) adj[i] = NULL;

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        Node* temp = newNode(v, w);
        temp->next = adj[u];
        adj[u] = temp;

        // For undirected graph, also add reverse edge
        // Uncomment if graph is undirected:
        // temp = newNode(u, w);
        // temp->next = adj[v];
        // adj[v] = temp;
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, source);

    return 0;
}
