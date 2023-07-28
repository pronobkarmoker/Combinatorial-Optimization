#include <stdio.h>

#define size 1001

int arr[size];

int fib(int n)
{
    if (n <= 1)
    {
        arr[n] = n;
        return n;
    }

    if (arr[n] == -1)
    {
        arr[n] = fib(n - 1) + fib(n - 2);
        return arr[n];
    }
    else
    {
        return arr[n];
    }
}

int main()
{
    int n;
    printf("enter n :");
    scanf("%d", &n);

    for (int i = 0; i < size; i++)
    {
        arr[i] = -1;
    }

    // arr[0] = 0;
    // arr[1] = 0;
    // arr[2] = 1;

    // for (int i = 3; i < n; i++)
    // {
    //     arr[i] = arr[i-1] + arr[i-2];
    // }

    printf("%d", fib(n));


    return 0;
}