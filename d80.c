#include <stdio.h>

#define INF 1000000000  // a large value to represent infinity
#define MAX 100         // maximum number of vertices

int main() {
    int n;
    scanf("%d", &n);

    int dist[MAX][MAX];

    // read adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            scanf("%d", &val);
            if (val == -1 && i != j) {
                dist[i][j] = INF;  // no edge
            } else {
                dist[i][j] = val;
            }
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // print shortest distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] >= INF/2)  // unreachable
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
