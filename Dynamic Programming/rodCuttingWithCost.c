#include <stdio.h>

int rodCut(int *price, int len);
int max(int a, int b);

int dp[1005];
int cost;

int main(int argc, char *argv[])
{
    freopen("rodCutCostInput.txt", "r", stdin);
    int len;
    scanf("%d", &len);
    scanf("%d", &cost);
    int price[len];
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &price[i]);
    }

    for (int i = 0; i < 1005; i++)
        dp[i] = -1;

    int ans = rodCut(price, len);
    printf("Maximum profit:%d\n", ans);

    return 0;
}

int rodCut(int *price, int len)
{
    if (len == 0)
        return 0;
    if (dp[len] != -1)
        return dp[len];
    int benefit = 0;
    int temp;
    for (int i = 1; i <= len; i++)
    {
        if (len - i >= 0)
        {
            benefit = max(benefit, (price[i - 1] - cost) + rodCut(price, len - i));
        }
    }
    return dp[len] = benefit;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}