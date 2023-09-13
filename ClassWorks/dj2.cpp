#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

#define SIZE 100
#define INFINITY 1000000

int w[SIZE][SIZE], d[SIZE], prv[SIZE];
int n = 0;
bool flag[SIZE];
string name[SIZE];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void initialize_single_source(int s)
{
    for (int v = 0; v < n; v++)
    {
        d[v] = INFINITY;
        prv[v] = -1;
    }
    d[s] = 0;

    pq.push(pair<int, int>(0, s));
}

void relax(int u, int v)
{
    if (d[v] > d[u] + w[u][v])
    {
        d[v] = d[u] + w[u][v];
        prv[v] = u;

        pq.push(pair<int, int>(d[v], v));
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

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < n; v++)
        {
            if (w[u][v] > 0)
            {
                relax(u, v);
            }
        }
    }
}

void readInput()
{
    int u, v;
    string s;
    while (cin >> s)
    {
        if (s == "END")
            break;

        for (u = 0; u < n; u++)
        {
            if (name[u] == s)
                break;
        }
        if (u == n)
        {
            name[n] = s;
            n++;
        }

        cin >> s;
        for (v = 0; v < n; v++)
        {
            if (name[v] == s)
                break;
        }
        if (v == n)
        {
            name[n] = s;
            n++;
        }

        cin >> w[u][v];
    }
}

void printGraph()
{
    int u, v;
    for (u = 0; u < n; u++ )
    {
        for(v = 0; v < n; v++)
        {
            cout << w[u][v] << " ";
        }
        cout << "\n";
    }
}

void printPath(int source, int destination)
{
    vector<string> path;
    int current = destination;
    while (current != source)
    {
        path.push_back(name[current]);
        current = prv[current];
    }
    path.push_back(name[source]);

    reverse(path.begin(), path.end());

    cout << "Shortest path from " << name[source] << " to " << name[destination] << ": ";
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i];
        if (i < path.size() - 1)
        {
            cout << " -> ";
        }
    }
    cout << endl;

    cout << "Distance: " << d[destination] << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    readInput();
    printGraph();

    int source = 1;       
    int destination = 1;

    dijkstra(source);
    printPath(source, destination+1);

    return 0;
}