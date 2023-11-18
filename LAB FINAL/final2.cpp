#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<int> chocolatecost(n);
    for (int i = 0; i < n; i++)
    {
        cin >> chocolatecost[i];
    }

    vector<vector<int>> BFF(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        BFF[x - 1].push_back(y - 1);
        BFF[y - 1].push_back(x - 1);
    }

    vector<bool> visited(n, false);
    long long totalChocolates = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            long long minCost = LLONG_MAX;
            queue<int> q;
            q.push(i);

            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                visited[curr] = true;
                minCost = min(minCost, (long long)chocolatecost[curr]);

                for (int BF : BFF[curr])
                {
                    if (!visited[BF])
                    {
                        q.push(BF);
                    }
                }
            }

            totalChocolates += minCost;
        }
    }

    cout << totalChocolates << endl;

    return 0;
}
