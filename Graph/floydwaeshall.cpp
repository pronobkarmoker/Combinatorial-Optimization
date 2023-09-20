#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int infinity = 1e9 + 10;
int dist[N][N];

void reconstructPath(vector<string>& cityName, int source, int destination) {
    if (dist[source][destination] == infinity) {
        cout << "No path exists between " << cityName[source] << " and " << cityName[destination] << endl;
        return;
    }

    vector<int> path;
    int current = source;

    while (current != destination) {
        path.push_back(current);
        int next = -1;
        for (int i = 1; i <= N; i++) {
            if (i != current && dist[current][destination] == dist[current][i] + dist[i][destination]) {
                next = i;
                break;
            }
        }

        current = next;
    }
    path.push_back(destination);

    cout << "Shortest path from " << cityName[source] << " to " << cityName[destination] << ": ";
    for (int i = 0; i < path.size(); i++) {
        cout << cityName[path[i]];
        if (i < path.size() - 1)
            cout << " -> ";
    }
    cout << endl;
    cout << "Distance: " << dist[source][destination] << endl;
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    unordered_map<string, int> cityIndex;
    vector<string> cityName;
    int index = 1;
    int edges;
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        string city1, city2;
        int wt;
        cin >> city1 >> city2 >> wt;

        if (cityIndex.find(city1) == cityIndex.end()) {
            cityIndex[city1] = index;
            cityName.push_back(city1);
            index++;
        }
        if (cityIndex.find(city2) == cityIndex.end()) {
            cityIndex[city2] = index;
            cityName.push_back(city2);
            index++;
        }

        int x = cityIndex[city1];
        int y = cityIndex[city2];

        dist[x][y] = wt;
    }

    int n = index - 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else if (dist[i][j] == 0)
                dist[i][j] = infinity;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    string sourceCity, destinationCity;
    cin >> sourceCity >> destinationCity;
    int source = cityIndex[sourceCity];
    int destination = cityIndex[destinationCity];
    reconstructPath(cityName, source, destination);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<dist[i][j]<< " ";
        }
        cout<<endl;
    }
    return 0;
}
