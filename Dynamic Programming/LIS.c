#include <stdio.h>

int LIS_Fast_DP(int arr[], int n, int L[], int L_prime[], int prev[])
{
    L[0] = -1;
    L_prime[0] = -1;
    prev[0] = -1;

    int L_len = 0;

    for (int i = 0; i < n; i++)
    {
        if (L[L_len] < arr[i])
        {
            L_len++;
            L[L_len] = arr[i];
            L_prime[L_len] = i;
            prev[i] = L_prime[L_len - 1];
        }
        else
        {
            int s = 0, h = L_len;

            while (s < h)
            {
                int m = (s + h) / 2;

                if (L[m] < arr[i])
                {
                    s = m + 1;
                }
                else
                {
                    h = m;
                }
            }

            L[s] = arr[i];
            L_prime[s] = i;
            prev[i] = L_prime[s - 1];
        }
    }

    return L_len;
}

void printLIS(int arr[], int prev[], int index)
{
    if (index == -1)
        return;
    printLIS(arr, prev, prev[index]);
    printf("%d ", arr[index]);
}

int main()
{
    int arr[] = {4,5,3,6,2,7,2,8,6,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int L[100];
    int L_prime[100];
    int prev[100];

    int len = LIS_Fast_DP(arr, n, L, L_prime, prev);
    printf("The length of the LIS is %d\n", len);

    printf("The LIS is: ");
    int last_index = L_prime[len];
    printLIS(arr, prev, last_index);
    printf("\n");

    return 0;
}
