#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define V 8  // Number of vertices in the bipartite graph
#define INF INT_MAX

// Function to find the minimum of two values
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Breadth-First Search (BFS) to find an augmenting path in the residual graph
bool bfs(int residualGraph[V][V], int source, int sink, int parent[]) {
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    visited[source] = true;
    parent[source] = -1;

    int queue[V];
    int front = 0, rear = 0;
    queue[rear++] = source;

    while (front < rear) {
        int u = queue[front++];
        for (int v = 0; v < V; v++) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                parent[v] = u;
                visited[v] = true;
                queue[rear++] = v;
            }
        }
    }

    // If we reached the sink node, there's an augmenting path
    return visited[sink];
}

// Ford-Fulkerson algorithm to find the maximum flow
int fordFulkerson(int graph[V][V], int source, int sink) {
    int u, v;
    int residualGraph[V][V];

    // Initialize the residual graph with the same capacities as the original graph
    for (u = 0; u < V; u++) {
        for (v = 0; v < V; v++) {
            residualGraph[u][v] = graph[u][v];
        }
    }

    int parent[V];  // Stores the parent node in augmenting path

    int maxFlow = 0;

    // Find augmenting paths and update the residual graph until no more augmenting paths exist
    while (bfs(residualGraph, source, sink, parent)) {
        int pathFlow = INF;
        // Find the minimum capacity in the augmenting path
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        // Update the residual capacities and reverse edges
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    int source = 0;
    int sink = 7;
    int maxMatching = fordFulkerson(graph, source, sink);

    printf("Maximum Matching in Bipartite Graph: %d\n", maxMatching);

    return 0;
}
