#include <bits/stdc++.h>
using namespace std;

int dp[100][100], s[100][100], p[100];
int MCM(int *p, int i, int j);
void print_optimal(int i, int j);

int main()
{
    freopen("mcminput.txt", "r", stdin);
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n;
    // int p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];

    cout << MCM(p, 1, n - 1) << endl;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    print_optimal(1, n - 1);
    cout << endl;

    return 0;
}
int MCM(int *p, int i, int j)
{
    if (i == j)
    {
        dp[i][j] = 0;
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        // dp[i][j] = min(dp[i][j], MCM(p, i, k) + MCM(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
        int q = MCM(p, i, k) + MCM(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        if (q < dp[i][j])
        {
            dp[i][j] = q;
            s[i][j] = k;
        }
    }
    return dp[i][j];
}
void print_optimal(int i, int j)
{
    if (i == j)
        cout << "A" << i;
    else
    {
        cout << "(";
        print_optimal(i, s[i][j]);
        print_optimal(s[i][j] + 1, j);
        cout << ")";
    }
}