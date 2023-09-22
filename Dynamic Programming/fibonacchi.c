#include <stdio.h>

#define size 1001

double fibo(int n);

double arr[size];

int main(int argc, char *argv[])
{

    int n;
    printf("Enter n:");
    scanf("%d", &n);

    for (int i = 0; i < size; i++)
        arr[i] = -1;

    printf("%dth fibonacchi: %.0lf\n", n, fibo(n));

    return 0;
}

double fibo(int n)
{
    if (n <= 1)
    {
        arr[n] = n;
        return n;
    }

    if (arr[n] == -1)
    {
        arr[n] = fibo(n - 1) + fibo(n - 2);
        return arr[n];
    }
    else
    {
        return arr[n];
    }
}