#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];    // visited array
int n;               // number of vertices

// DFS function with parent tracking
int dfs(int v, int parent) {
    visited[v] = 1;

    for (int u = 0; u < n; u++) {
        if (adj[v][u]) {  // edge exists
            if (!visited[u]) {
                if (dfs(u, v)) return 1;  // cycle found
            } else if (u != parent) {
                return 1;  // visited neighbor not parent → cycle
            }
        }
    }
    return 0;
}

int main() {
    int edges;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;  // undirected graph
    }

    // initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // check for cycle in all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}