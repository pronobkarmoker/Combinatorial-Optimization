#include <bits/stdc++.h>
using namespace std;

int lcs(string &s1, string &s2, int n, int m);
int dp[100][100];

int main()
{
    freopen("lcsinput.txt", "r", stdin);

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            dp[i][j] = -1;
        }
    }

    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    cout << "Longest length:";
    cout << lcs(s1, s2, n, m) << endl;
    ;

    return 0;
}

int lcs(string &s1, string &s2, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (s1[n - 1] == s2[m - 1])
    {
        dp[n][m] = 1 + lcs(s1, s2, n - 1, m - 1);
    }
    else
    {
        dp[n][m] = max(lcs(s1, s2, n - 1, m), lcs(s1, s2, n, m - 1));
    }
    return dp[n][m];
}