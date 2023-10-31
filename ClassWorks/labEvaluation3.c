#include <stdio.h>

#define MAX_NODES 100
#define INF 1000000

int bandwidth[MAX_NODES][MAX_NODES];

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n, s, t, e;
    scanf("%d", &n);
    scanf("%d %d %d", &s, &t, &e);

    // Initialize the bandwidth matrix with INF values
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                bandwidth[i][j] = INF;
            }
        }
    }

    // Read and store connection information
    for (int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        bandwidth[u][v] = bandwidth[v][u] = w; // Connections are bi-directional
    }

    // Floyd-Warshall algorithm to compute the bandwidth
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                bandwidth[i][j] = min(bandwidth[i][j], max(bandwidth[i][k], bandwidth[k][j]));
            }
        }
    }

    // Output the result
    printf("The bandwidth is %d\n", bandwidth[s][t]);

    return 0;
}
