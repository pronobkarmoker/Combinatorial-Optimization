#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define V 9 // Number of vertices in the graph, including source and sink
#define INF INT_MAX

int min(int a, int b)
{
    return (a < b) ? a : b;
}

bool bfs(int residualGraph[V][V], int source, int sink, int parent[])
{
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    visited[source] = true;
    parent[source] = -1;
    int queue[V];
    int front = 0, rear = 0;
    queue[rear++] = source;

    while (front < rear)
    {
        int u = queue[front++];
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && residualGraph[u][v] > 0)
            {
                parent[v] = u;
                visited[v] = true;
                queue[rear++] = v;
            }
        }
    }

    return visited[sink];
}

int fordFulkerson(int graph[V][V], int source[], int numSources, int sink[], int numSinks)
{
    int u, v;
    int residualGraph[V][V];

    for (u = 0; u < V; u++)
    {
        for (v = 0; v < V; v++)
        {
            residualGraph[u][v] = graph[u][v];
        }
    }

    int parent[V];
    int maxFlow = 0;

    for (int i = 0; i < numSources; i++)
    {
        while (bfs(residualGraph, source[i], sink[i], parent))
        {
            int pathFlow = INF;
            for (v = sink[i]; v != source[i]; v = parent[v])
            {
                u = parent[v];
                pathFlow = min(pathFlow, residualGraph[u][v]);
            }

            for (v = sink[i]; v != source[i]; v = parent[v])
            {
                u = parent[v];
                residualGraph[u][v] -= pathFlow;
                residualGraph[v][u] += pathFlow;
            }

            maxFlow += pathFlow;
        }
    }

    return maxFlow;
}

int main()
{
    int graph[V][V] = {
        {0, 0, 4, 0, 0, 0, 0, 0, 0},
        {0, 0, 5, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 7, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 5, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 5, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 4, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    int source[] = {0, 1, 2};
    int numSources = 3;
    int sink[] = {7, 8, 5};
    int numSinks = 3;

    int maxFlow = fordFulkerson(graph, source, numSources, sink, numSinks);

    printf("Maximum Flow: %d\n", maxFlow);

    return 0;
}
