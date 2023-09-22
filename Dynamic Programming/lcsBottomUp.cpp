#include <bits/stdc++.h>
using namespace std;

void print_lcs(vector<vector<int>> dp, string &s1, string &s2, int n, int m);

int main()
{
    freopen("lcsinput.txt", "r", stdin);

    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    cout << "Longest length:";
    cout << dp[n][m] << endl;
    cout << "Subsequences:";
    print_lcs(dp, s1, s2, n, m);
    cout << endl;

    return 0;
}
void print_lcs(vector<vector<int>> dp, string &s1, string &s2, int n, int m)
{
    if (n == 0 || m == 0)
        return;
    if (s1[n - 1] == s2[m - 1])
    {
        print_lcs(dp, s1, s2, n - 1, m - 1);
        cout << s1[n - 1] << " ";
    }
    else if (dp[n][m - 1] > dp[n - 1][m])
        print_lcs(dp, s1, s2, n, m - 1);
    else
        print_lcs(dp, s1, s2, n - 1, m);
}