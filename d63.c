#include <stdio.h>
#include <stdlib.h>

int visited[1000];
int n;

void dfs(int u, int adj[][1000]) {
    visited[u] = 1;
    printf("%d ", u);
    for (int v = 0; v < n; v++) {
        if (adj[u][v] && !visited[v]) {
            dfs(v, adj);
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
        adj[v][u] = 1; // remove this line if graph is directed
    }
    scanf("%d", &s);
    dfs(s, adj);
    return 0;
}