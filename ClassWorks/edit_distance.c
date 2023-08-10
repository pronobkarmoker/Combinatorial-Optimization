#include <stdio.h>
#include <string.h>

#define ra 1
#define la 2
#define ua 3
#define da 4

// char X[] = "heater";
// char Y[] = "speak";

int min(int a, int b, int c)
{
    if (a < b)
    {
        return (a < c) ? a : c;
    }
    else
    {
        return (b < c) ? b : c;
    }
}

void PRINT(char *X, char *Y, int i, int j)
{

    if (i ==0 || j == 0)
    {
        return;
    }

    if (X[i] = da)
    {
        PRINT(X, Y, i - 1, j - 1);
        printf("%d ", X[i]);
    }

    else if (X[i] = ua)

        PRINT(X, Y, i - 1, j);

    else
        PRINT(X, Y, i, j - 1);
}

int Distance(char *X, char *Y)
{
    int m = strlen(X);
    int n = strlen(Y);

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
    }

    return dp[m][n];
}

int main()
{
    char X[] = "complete";
    char Y[] = "computer";

    int result = Distance(X, Y);
    printf("Edit distance between '%s' and '%s': %d\n", X, Y, result);

    PRINT(X,Y,strlen(X),strlen(Y));

    return 0;
}
