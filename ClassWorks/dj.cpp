#include <iostream>
#include <queue>
#include <string>
#include <map>

using namespace std;

#define SIZE 100
#define INFINITY 1000000

int w[SIZE][SIZE], d[SIZE], previous[SIZE];
int n = 0;
bool flag[SIZE];
string name[SIZE];

void initialize_single_source(int s)
{
    for (int v = 0; v < n; v++)
    {
        d[v] = INFINITY;
        previous[v] = -1;
    }
    d[s] = 0;
}

void relax(int u, int v)
{
    if (d[v] > d[u] + w[u][v])
    {
        d[v] = d[u] + w[u][v];
        previous[v] = u;
    }
}

int extract_min()
{
    int m = INFINITY, index = -1;

    for (int i = 0; i < n; i++)
    {
        if (flag[i] && m > d[i])
        {
            m = d[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int s)
{
    initialize_single_source(s);

    for (int i = 0; i < n; i++)
    {
        flag[i] = true;
    }
    int queueSize = n;
    while (queueSize)
    {
        int u = extract_min();
        for (int v = 0; v < n; v++)
        {
            if (w[u][v] > 0)
            {
                relax(u, v);
            }
        }
        queueSize--;
    }
}

void readInput()
{
    map<string, int> cityIndex;
    int u, v, weight;
    string s1, s2;
    while (cin >> s1 >> s2 >> weight)
    {
        if (cityIndex.find(s1) == cityIndex.end())
        {
            cityIndex[s1] = n;
            name[n] = s1;
            n++;
        }
        if (cityIndex.find(s2) == cityIndex.end())
        {
            cityIndex[s2] = n;
            name[n] = s2;
            n++;
        }

        u = cityIndex[s1];
        v = cityIndex[s2];
        w[u][v] = w[v][u] = weight; 
    }
}

void printShortestPath(int start, int end)
{
    if (d[end] == INFINITY)
    {
        cout << "No path found from " << name[start] << " to " << name[end] << endl;
        return;
    }

    cout << "Shortest path from " << name[start] << " to " << name[end] << ": ";
    int current = end;
    while (current != start)
    {
        cout << name[current] << " <- ";
        current = previous[current];
    }
    cout << name[start] << ", Distance: " << d[end] << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    readInput();

    
    int start = 0; // Index of Dhaka
    int end = 3;   // Index of Sylhet

    dijkstra(start);
    printShortestPath(start, end);

    return 0;
}
