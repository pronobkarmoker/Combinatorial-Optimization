#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define V 6  // Number of vertices in the undirected graph

// Function to find the minimum of two values
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to perform the Ford-Fulkerson algorithm
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
        int pathFlow = INT_MAX;
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
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 0, 0, 9, 0, 20},
        {0, 0, 0, 0, 7, 4},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };

    int source = 0;
    int sink = 5;
    int maxFlow = fordFulkerson(graph, source, sink);

    printf("Maximum Flow from Source to Sink: %d\n", maxFlow);

    return 0;
}
