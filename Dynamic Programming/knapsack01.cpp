#include <bits/stdc++.h>
using namespace std;

int item, knapsack;
int dp[100][100];

int main()
{
    freopen("knapsackinput.txt", "r", stdin);

    cin >> item >> knapsack;

    int price[item + 1], weight[item + 1];
    int dp[item + 1][knapsack + 1];
    int i, w;

    for (i = 1; i <= item; i++)
        cin >> weight[i];
    for (i = 1; i <= item; i++)
        cin >> price[i];

    for (w = 0; w <= knapsack; w++)
        dp[0][w] = 0;
    for (i = 0; i <= item; i++)
        dp[i][0] = 0;

    for (i = 1; i <= item; i++)
    {
        for (w = 1; w <= knapsack; w++)
        {
            if (weight[i] <= w)
            {
                dp[i][w] = max(price[i] + dp[i - 1][w - weight[i]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    cout << "Max profit:" << dp[item][knapsack] << endl;
    i = item;
    int j = knapsack;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] == dp[i - 1][j])
        {
            i--;
        }
        else
        {
            cout << "Item: " << i << endl;
            j = j - weight[i];
            i--;
        }
    }
}