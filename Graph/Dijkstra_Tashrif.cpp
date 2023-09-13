#include <bits/stdc++.h>
using namespace std;
#define mx 100

map<string, int> names;
int dis[mx];
int graph[mx][mx] = {0};
int pre[mx];

void read()
{
    string s;
    int w, x, y, i = 0;
    freopen("inputG.txt", "r", stdin);
    while (cin >> s)
    {
        if (s == "END")
            break;

        if (names[s] == 0)
        {
            names[s] = ++i;
        }
        x = names[s];
        cin >> s;
        if (names[s] == 0)
        {
            names[s] = ++i;
        }
        y = names[s];
        cin >> w;
        graph[x][y] = w;
    }
}

void initSource(string s)
{
    for (int i = 0; i < names.size(); i++)
    {
        dis[i] = INT_MAX;
        pre[i] = -1;
    }
    dis[names[s]] = 0;
}

void relax(int u, int v)
{
    if (dis[v] > dis[u] + graph[u][v])
    {
        dis[v] = dis[u] + graph[u][v];
        pre[v] = u;
    }
}
void dijkstra(string s)
{
    initSource(s);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({dis[names[s]], names[s]});

    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        for (int i = 0; i < names.size(); i++)
        {
            if (graph[u][i])
            {
                relax(u, i);
                q.push({dis[i], i});
            }
        }
    }
}
void printGraph()
{
    for (int i = 1; i <= names.size(); i++)
    {
        for (int j = 1; j <= names.size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void printPath(int i)
{
    if (i == -1)
        return;
    printPath(pre[i]);
    for (auto x : names)
    {
        if (x.second == i)
        {
            cout << x.first << " ";
            break;
        }
    }
}
int main()
{
    string dest;
    read();
    // dijkstra("Dhaka");
    printGraph();
    dijkstra("Dhaka");
    cout << "Enter dest\n";
    cin >> dest;
    printPath(names[dest]);
    return 0;
}