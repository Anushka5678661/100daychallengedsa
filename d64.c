#include <stdio.h>
#include <stdlib.h>

int visited[1000];
int n;

void bfs(int s, int adj[][1000]) {
    int queue[1000], front = 0, rear = 0;
    visited[s] = 1;
    queue[rear++] = s;
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
}

int main() {
    int m, s;
    scanf("%d %d", &n, &m);
    int adj[1000][1000] = {0};
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // remove if graph is directed
    }
    scanf("%d", &s);
    bfs(s, adj);
    return 0;
}