#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void topologicalSort(int n, int adj[MAX][MAX]) {
    int indegree[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    int count = 0;

    // Step 1: Compute in-degree
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (adj[i][j] == 1)
                indegree[j]++;

    // Step 2: Enqueue all vertices with in-degree 0
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    // Step 3: Process queue
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        count++;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0)
                    queue[rear++] = v;
            }
        }
    }

    // Step 4: Check cycle
    if (count != n)
        printf("\nGraph has a cycle. Topological sort not possible.\n");
}

int main() {
    int n = 6;
    int adj[MAX][MAX] = {
        {0,1,1,0,0,0},
        {0,0,0,1,0,0},
        {0,0,0,1,0,0},
        {0,0,0,0,1,1},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0}
    };

    printf("Topological Sort: ");
    topologicalSort(n, adj);
    return 0;
}
