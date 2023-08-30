#include <stdio.h>
#include <string.h>

int c[100][100];
char b[100][100];

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

void initialize(int m, int n)
{
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            c[i][j] = -1;
        }
    }
}

int memoizedLCS(char X[], char Y[], int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (c[m][n] != -1)
    {
        return c[m][n];
    }
    if (X[m - 1] == Y[n - 1])
    {
        c[m][n] = 1 + memoizedLCS(X, Y, m - 1, n - 1);
        b[m][n] = '\\';
    }
    else
    {
        int len1 = memoizedLCS(X, Y, m - 1, n);
        int len2 = memoizedLCS(X, Y, m, n - 1);
        if (len1 >= len2)
        {
            c[m][n] = len1;
            b[m][n] = '|';
        }
        else
        {
            c[m][n] = len2;
            b[m][n] = '-';
        }
    }
    return c[m][n];
}

void printLCS(char X[], int m, int n)
{
    if (m == 0 || n == 0)
    {
        return;
    }
    if (b[m][n] == '\\')
    {
        printLCS(X, m - 1, n - 1);
        printf("%c", X[m - 1]);
    }
    else if (b[m][n] == '|')
    {
        printLCS(X, m - 1, n);
    }
    else
    {
        printLCS(X, m, n - 1);
    }
}

int main()
{
    char X[] = "ABCBDA";
    char Y[] = "BDCABA";

    int m = strlen(X);
    int n = strlen(Y);

    initialize(m, n);

    int length = memoizedLCS(X, Y, m, n);

    printf("Length of Longest Common Subsequence: %d\n", length);
    printf("Longest Common Subsequence: ");
    printLCS(X, m, n);
    printf("\n");

    return 0;
}
