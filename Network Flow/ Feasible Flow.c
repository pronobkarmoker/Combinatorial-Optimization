#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define V 7  // Number of vertices in the graph

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

int isFeasibleFlow(int graph[V][V], int vertexWeights[V], int source, int sink) {
    int flow = fordFulkerson(graph, source, sink);
    for (int i = 0; i < V; i++) {
        if (i != source && i != sink) {
            int inflow = 0;
            int outflow = 0;
            for (int j = 0; j < V; j++) {
                inflow += graph[j][i];
                outflow += graph[i][j];
            }
            if (inflow - outflow != vertexWeights[i]) {
                return 0;  // Not a feasible flow
            }
        }
    }
    return flow;
}

int main() {
    int graph[V][V] = {
        {0, 3, 0, 3, 0, 0, 0},
        {0, 0, 2, 0, 0, 0, 0},
        {0, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 3, 0, 0},
        {0, 0, 0, 0, 0, 2, 0},
        {0, 0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 0, 0}
    };

    int vertexWeights[V] = {3, -2, -2, 3, -2, -3, -2};
    int source = 0;
    int sink = 6;

    int feasibleFlow = isFeasibleFlow(graph, vertexWeights, source, sink);

    if (feasibleFlow) {
        printf("Feasible Flow: %d\n", feasibleFlow);
    } else {
        printf("No Feasible Flow exists.\n");
    }

    return 0;
}
