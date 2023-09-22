#include <stdio.h>

int rodCut(int *price, int len);
int max(int a, int b);

int dp[55], priceLen, cut[100];

int main(int argc, char *argv[])
{
    freopen("rodCutAssignment.txt", "r", stdin);
    int len;
    scanf("%d", &len);
    scanf("%d", &priceLen);
    int price[priceLen];
    for (int i = 0; i < priceLen; i++)
    {
        scanf("%d", &price[i]);
    }

    for (int i = 0; i < 55; i++)
        dp[i] = -1;

    int ans = rodCut(price, len);
    printf("Maximum profit: %d\n", ans);
    printf("Cutting lengths:\n");
    while (len > 0)
    {
        printf("%d ", cut[len]);
        len = len - cut[len];
    }
    printf("\n");

    return 0;
}

int rodCut(int *price, int len)
{
    if (len == 0)
        return 0;
    if (dp[len] != -1)
        return dp[len];
    int benefit = 0;
    for (int i = 1; i <= len && i <= priceLen; i++)
    {
        // if(len-i>=0) benefit = max(benefit, price[i-1] + rodCut(price, len - i));
        if (len - i >= 0)
        {
            int temp = price[i - 1] + rodCut(price, len - i);
            if (temp > benefit)
            {
                benefit = temp;
                cut[len] = i;
            }
        }
    }
    return dp[len] = benefit;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}