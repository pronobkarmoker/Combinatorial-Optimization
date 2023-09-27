#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int dest;
    int weight;
};

struct Graph
{
    int V;
    vector<vector<Edge>> adj;

    Graph(int vertices)
    {
        V = vertices;
        adj.resize(vertices);
    }

    void addEdge(int src, int dest, int weight)
    {
        adj[src].push_back({dest, weight});
        adj[dest].push_back({src, weight});
    }
};

struct Vertex
{
    int id;
    int key;
};

struct CompareVertex
{
    bool operator()(const Vertex &v1, const Vertex &v2) const
    {
        return v1.key > v2.key;
    }
};

void primMST(Graph &graph, int r)
{
    int V = graph.V;
    vector<int> key(V, numeric_limits<int>::max());
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    key[r] = 0;
    priority_queue<Vertex, vector<Vertex>, CompareVertex> pq;
    pq.push({r, 0});

    while (!pq.empty())
    {
        int u = pq.top().id;
        pq.pop();

        inMST[u] = true;

        for (const Edge &edge : graph.adj[u])
        {
            int v = edge.dest;
            int weight = edge.weight;

            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
                parent[v] = u;
                pq.push({v, key[v]});
            }
        }
    }

    cout << "Edges in the MST:" << endl;
    for (int i = 0; i < V; ++i)
    {
        if (i != r)
        {
            cout << "Edge: " << parent[i] << " - " << i << " Weight: " << key[i] << endl;
        }
    }
}

int main()
{
    int V = 5;
    Graph graph(V);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 6);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 8);
    graph.addEdge(1, 4, 5);
    graph.addEdge(2, 4, 7);
    graph.addEdge(3, 4, 9);

    int root = 0;

    primMST(graph, root);

    return 0;
}
