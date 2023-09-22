#include <bits/stdc++.h>
using namespace std;

void maxSumInterval(int *prev, int i);
int findMaxIndex(int *sum);
int arr[100];

int main()
{

    freopen("msinput.txt", "r", stdin);

    int size;
    cin >> size;
    arr[size + 1];
    int sum[size + 1], prev[size + 1];
    sum[0] = prev[0] = 0;
    int i;
    for (i = 1; i <= size; i++)
        cin >> arr[i];

    for (i = 1; i <= size; i++)
    {
        sum[i] = sum[i - 1] + arr[i];
        prev[i] = i - 1;
        if (arr[i] > sum[i])
        {
            sum[i] = arr[i];
            prev[i] = 0;
        }
    }
    int index, max = 0;
    for (int i = 1; i <= size; i++)
    {
        if (sum[i] > max)
        {
            max = sum[i];
            index = i;
        }
    }
    cout << "Max sum interval: ";
    maxSumInterval(prev, index);
    cout << endl;
    return 0;
}
void maxSumInterval(int *prev, int i)
{
    if (prev[i] == 0)
        cout << arr[i] << " ";
    if (prev[i] > 0)
    {
        maxSumInterval(prev, prev[i]);
        cout << arr[i] << " ";
    }
}