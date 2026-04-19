#include <stdio.h>
#include <limits.h>

#define MAX 1000

int n, m;
int graph[MAX][MAX];

int primMST() {
    int key[MAX], mstSet[MAX];
    int totalWeight = 0;

    // Initialize arrays
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // Start from vertex 1
    key[1] = 0;

    for (int count = 1; count <= n; count++) {
        // Find vertex with minimum key not in MST
        int u = -1, min = INT_MAX;
        for (int v = 1; v <= n; v++) {
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        mstSet[u] = 1;          // Include vertex in MST
        totalWeight += key[u];  // Add edge weight

        // Update key values of adjacent vertices
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}

int main() {
    scanf("%d %d", &n, &m);

    // Initialize adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }

    int result = primMST();
    printf("%d\n", result);

    return 0;
}
