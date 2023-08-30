#include <stdio.h>

void matrixChainOrder(int p[], int n, int m[][n], int s[][n])
{
    for (int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            m[i][j] = 999999; // Use a sufficiently large value as initial minimum

            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printOptimalParenthesis(int s[][7], int i, int j)
{
    if (i == j)
        printf("A%d", i);
    else
    {
        printf("(");
        printOptimalParenthesis(s, i, s[i][j]);
        printOptimalParenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main()
{
    int n = 6;                             // Number of matrices
    int p[] = {30, 35, 15, 5, 10, 20, 25}; // Matrix dimensions

    int m[n + 1][n + 1]; // Cost matrix
    int s[n + 1][n + 1]; // Split matrix

    matrixChainOrder(p, n, m, s);

    printf("Cost Matrix m:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    printf("\nSplit Matrix s:\n");
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            printf("%d\t", s[i][j]);
        }
        printf("\n");
    }

    printf("\nOptimal Parenthesis: ");
    printOptimalParenthesis(s, 1, n);
    printf("\n");

    return 0;
}
