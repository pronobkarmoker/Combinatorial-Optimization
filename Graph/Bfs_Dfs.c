#include <stdio.h>
#include "Queue.h"

void BFS(int graph[][7], int start, int n)
{
    int i = start;
    // struct Queue q;
    int visited[7] = {0};

    printf("%d ", i);
    visited[i] = 1;

    enqueue(i);

    while (!isEmpty())
    {
        i = dequeue();
        for (int j = 1; j < 7; j++)
        {
            if (graph[i][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

void DFS(int graph[][7], int start, int n)
{
    static int visited[7] = {0};

    if (visited[start] == 0)
    {
        printf("%d ", start);
        visited[start] = 1;
        for (int j = 1; j < n; j++)
        {
            if (graph[start][j] == 1 && visited[j] == 0)
            {
                DFS(graph, j, n);
            }
        }
    }
}

int main()
{
    int graph[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 1, 1, 0, 0, 0},
                       {0, 1, 0, 0, 1, 0, 0},
                       {0, 1, 0, 0, 1, 0, 0},
                       {0, 0, 1, 1, 0, 1, 1},
                       {0, 0, 0, 0, 1, 0, 0},
                       {0, 0, 0, 0, 1, 0, 0}};

    printf("BFS : ");
    BFS(graph, 3, 7);
    printf("\n\n");

    printf("DFS : ");
    DFS(graph, 3, 7);
    return 0;
}