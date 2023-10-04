#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define V 6

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

int fordFulkerson(int graph[V][V], int source, int sink)
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

    while (bfs(residualGraph, source, sink, parent))
    {
        int pathFlow = INT_MAX;

        for (v = sink; v != source; v = parent[v])
        {
            u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        printf("Augmenting Path: ");
        for (v = sink; v != source; v = parent[v])
        {
            u = parent[v];
            printf("%d -> ", u);
        }
        printf("%d\n", sink);

        for (v = sink; v != source; v = parent[v])
        {
            u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main()
{

    freopen("outFORD.txt", "w", stdout);
    int graph[V][V] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}};

    int source = 0;
    int sink = 5;
    int maxFlow = fordFulkerson(graph, source, sink);

    printf("Maximum Flow : %d\n", maxFlow);

    return 0;
}
