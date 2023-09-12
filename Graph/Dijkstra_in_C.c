#include <stdio.h>
#include <math.h>
#define size 4
#define visited 1
#define unvisited 2

int graph[4][4] = {0};
enum cities
{
    A,
    B,
    C,
    D,
    E,
    F,
    G
};
struct vertex
{
    char city;
    int cost;
    int path;
    int state
};

struct vertex vartices[4];

void dijkstra(int source, int destination)
{
    for (int v = 0; v < size; v++)
    {
        vartices[v].city = v + 65;
        vartices[v].cost = INFINITY;
        vartices[v].path = -1;
        vartices[v].state = unvisited;
    }

    vartices[source].cost = 0;
    for (;;)
    {
        int minCost = INFINITY, current = -1;
        for (int v = 0; v < size; v++)
        {
            if (vartices[v].cost < minCost && vartices[v].state == unvisited)
            {
                minCost = vartices[v].cost;
                current = v;
            }
        }
        if (current == -1)
        {
            break;
        }

        vartices[current].state = visited;
        for (int v = 0; v < size; v++)
        {
            if (graph[current][v] != 0 && vartices[v].state == unvisited && graph[current][v] != -1)
            {
                if (vartices[current].cost + graph[current][v] < vartices[v].cost)
                {
                    vartices[v].cost = vartices[current].cost + graph[current][v];
                    vartices[v].path = current;
                }
            }
        }
    }

    if (vartices[destination].cost == INFINITY)
    {
        printf("NOT CONNECTED!!!");
    }
    else
    {
        int i, x, path[50], cost = 0, count = 0;
        while (destination != source)
        {
            count++;
            path[count] = destination;
            x = vartices[destination].path;
            cost += graph[x][destination];
            destination = x;
        }
        count++;
        path[count] = source;
        for (int i = count; i > 0; i--)
        {
            printf("%c ", vartices[path[i]].city);
            if (i > 1)
                printf("-");
        }
        printf("%d\n", cost);
    }
}
void scanarray()
{
    int c;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &c);
            graph[i][j] = c;
        }
    }
}

int main(void)
{
    scanarray();
    dijkstra(A, D);
    return 0;
}
