#include <bits/stdc++.h>
using namespace std;

int arr[100];
void printLIS(int *prev, int index);

int main()
{
    freopen("lisinput.txt", "r", stdin);

    int size;
    cin >> size;
    arr[size + 1];
    int length[size + 1], prev[size + 1], maxLength = 0, maxIndex = 0;
    prev[0] = -1;
    int i;
    for (i = 1; i <= size; i++)
        cin >> arr[i];

    memset(length, 0, sizeof length);

    for (int i = 1; i <= size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((arr[j] < arr[i]) && (length[j] + 1 > length[i]))
            {
                length[i] = length[j] + 1;
                prev[i] = j;
            }
        }

        if (length[i] >= maxLength)
        {
            maxLength = length[i];
            maxIndex = i;
        }
    }
    printf("Longest increasing subsequence:");
    printLIS(prev, maxIndex);
    cout << endl;

    return 0;
}
void printLIS(int *prev, int index)
{
    if (index == 0)
        return;
    printLIS(prev, prev[index]);
    cout << arr[index] << " ";
}