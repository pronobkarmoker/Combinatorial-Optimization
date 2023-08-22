#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int item, int max_w, int wt[], int value[])
{
    int p[item + 1][max_w + 1];

    for (int i = 0; i <= item; i++)
    {
        for (int w = 0; w <= max_w; w++)
        {
            if (i == 0 || w == 0)
            {
                p[i][w] = 0;
            }
            else if (wt[i - 1] > w)
            {
                p[i][w] = p[i - 1][w];
            }
            else
            {
                p[i][w] = max(p[i - 1][w], p[i - 1][w - wt[i - 1]] + value[i - 1]);
            }
        }
    }

    printf("0-1 knapsack table \n\n");
    for (int i = 0; i <= item; i++)
    {
        for (int w = 0; w <= max_w; w++)
        {
            printf("%d\t", p[i][w]);
        }
        printf("\n");
    }

    return p[item][max_w];
}

int main()
{
    int item = 4;
    int max_w = 5;
    int wt[] = {2, 1, 3, 2};
    int value[] = {12, 10, 20, 15};

    int result = knapsack(item, max_w, wt, value);

    printf("\nMax Profit : %d\n", result);

    return 0;
}

/*

output 


0-1 knapsack table 

0       0       0       0       0       0
0       0       12      12      12      12
0       10      12      22      22      22
0       10      12      22      30      32
0       10      15      25      30      37

Max Profit : 37

*/
