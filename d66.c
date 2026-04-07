#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// add edge u -> v
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS utility
bool dfs(int node, struct Node* adj[], bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;

    struct Node* temp = adj[node];
    while (temp != NULL) {
        int neigh = temp->vertex;
        if (!visited[neigh] && dfs(neigh, adj, visited, recStack))
            return true;
        else if (recStack[neigh])
            return true;
        temp = temp->next;
    }

    recStack[node] = false;
    return false;
}

// cycle detection
bool isCyclic(int V, struct Node* adj[]) {
    bool visited[V];
    bool recStack[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i] && dfs(i, adj, visited, recStack))
            return true;
    }
    return false;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Node* adj[V];
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    if (isCyclic(V, adj))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}