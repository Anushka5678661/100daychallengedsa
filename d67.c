#include <stdio.h>
#include <stdlib.h>

// Structure for adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Structure for adjacency list
struct AdjList {
    struct Node* head;
};

// Structure for graph
struct Graph {
    int V;                // number of vertices
    struct AdjList* array;
};

// Utility function to create a new adjacency list node
struct Node* newNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = v;
    node->next = NULL;
    return node;
}

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; i++)
        graph->array[i].head = NULL;
    return graph;
}

// Add edge to graph (u -> v)
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* node = newNode(v);
    node->next = graph->array[u].head;
    graph->array[u].head = node;
}

// DFS utility function
void DFSUtil(struct Graph* graph, int v, int visited[], int* stack, int* top) {
    visited[v] = 1;

    struct Node* temp = graph->array[v].head;
    while (temp != NULL) {
        if (!visited[temp->vertex])
            DFSUtil(graph, temp->vertex, visited, stack, top);
        temp = temp->next;
    }

    // Push current vertex to stack after visiting neighbors
    stack[(*top)++] = v;
}

// Function to perform Topological Sort
void topologicalSort(struct Graph* graph) {
    int V = graph->V;
    int visited[V];
    int stack[V];
    int top = 0;

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    // Call DFS for all unvisited vertices
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            DFSUtil(graph, i, visited, stack, &top);
    }

    // Print contents of stack in reverse order
    printf("Topological Ordering: ");
    for (int i = top - 1; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

// Driver code
int main() {
    int V = 6;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    return 0;
}
