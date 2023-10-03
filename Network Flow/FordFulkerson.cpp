#include <bits/stdc++.h>
using namespace std;

#define SIZE 10
#define INF 1e6 + 10

int graph[SIZE][SIZE];
vector<int> dist(SIZE, INF);
vector<bool> visited(SIZE, false);
vector<int> path;
vector<int> par(SIZE);
int m = INT_MAX;

void generatePath(int x)
{
    if (x == -1)
        return;
    generatePath(par[x]);
    path.push_back(x);
}

bool BFS(int source, int destination, int num_vertex)
{
    path.clear();
    m = INT_MAX;
    for (int i = 0; i < SIZE; i++)
        visited[i] = false;
    queue<int> q;
    q.push(source);
    visited[source] = true;
    par[source] = -1;
    while (!q.empty())
    {
        int v = q.front();
        if (v == destination)
        {
            generatePath(6);
            return true;
        }
        q.pop();
        for (int i = 1; i <= num_vertex; i++)
        {
            if (!visited[i] && graph[v][i] != INF)
            {
                if (graph[v][i] < m)
                    m = graph[v][i];
                par[i] = v;
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return false;
}
int main()
{
    freopen("Fulkerson.txt", "r", stdin);
    freopen("FulkersonOUT.txt", "w", stdout);
    int num_vertex, num_edge, from, to, dis;
    cin >> num_vertex >> num_edge;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            graph[i][j] = INF;
        }
    }
    for (int i = 0; i < num_edge; i++)
    {
        cin >> from >> to >> dis;
        graph[from][to] = dis;
    }
    int flow = 0;
    while (BFS(1, 6, 6))
    {
        // for(auto p : path){
        //     cout << p << " ";
        // }
        // cout << endl;
        for (int i = 0; i < path.size() - 1; i++)
        {
            graph[path[i]][path[i + 1]] -= m;
            if (graph[path[i]][path[i + 1]] == 0)
                graph[path[i]][path[i + 1]] = INF;
            if (graph[path[i + 1]][path[i]] != INF)
                graph[path[i + 1]][path[i]] += m;
            else
                graph[path[i + 1]][path[i]] = m;
        }
        flow += m;
    }
    cout << flow << endl;
}