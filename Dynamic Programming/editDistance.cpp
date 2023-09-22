#include <bits/stdc++.h>
using namespace std;

#define min3(a, b, c) min(a, min(b, c))

int main()
{
    freopen("edinput.txt", "r", stdin);

    string s1, s2;
    cin >> s1 >> s2;

    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int i = 1; i <= n; i++)
        dp[0][i] = i;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            }
        }
    }
    cout << "Edit Diatance:";
    cout << dp[m][n] << endl;

    return 0;
}