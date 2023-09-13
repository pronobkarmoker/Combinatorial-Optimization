#include <stdio.h>
#include <math.h>
#define size 5
#define visited 1
#define unvisited 2

#define LARGE_INT 2147483647 

int graph[5][5] = {0};
enum cities
{
    Dhaka,
    Chattogram,
    Khulna,
    Rajshahi,
    Sylhet
};
struct vertex
{
    char city;
    int cost;
    int path;
    int state;
};

struct vertex vertices[5];

void dijkstra(int source, int destination)
{
    for (int v = 0; v < size; v++)
    {
        vertices[v].city = v + 65;
        vertices[v].cost = LARGE_INT;
        vertices[v].path = -1;
        vertices[v].state = unvisited;
    }

    vertices[source].cost = 0;
    for (;;)
    {
        int minCost = LARGE_INT, current = -1;
        for (int v = 0; v < size; v++)
        {
            if (vertices[v].cost < minCost && vertices[v].state == unvisited)
            {
                minCost = vertices[v].cost;
                current = v;
            }
        }
        if (current == -1)
        {
            break;
        }

        vertices[current].state = visited;
        for (int v = 0; v < size; v++)
        {
            if (graph[current][v] != 0 && vertices[v].state == unvisited && graph[current][v] != -1)
            {
                if (vertices[current].cost + graph[current][v] < vertices[v].cost)
                {
                    vertices[v].cost = vertices[current].cost + graph[current][v];
                    vertices[v].path = current;
                }
            }
        }
    }

    if (vertices[destination].cost == LARGE_INT)
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
            x = vertices[destination].path;
            cost += graph[x][destination];
            destination = x;
        }
        count++;
        path[count] = source;
        for (int i = count; i > 0; i--)
        {
            printf("%c ", vertices[path[i]].city);
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
    dijkstra(Dhaka, Sylhet);
    return 0;
}
