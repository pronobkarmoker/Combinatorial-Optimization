#include <bits/stdc++.h>
using namespace std;

int arr[100];
void printLIS(int *prev, int index);

int main()
{
    freopen("lisinput.txt", "r", stdin);

    int size, i;
    cin >> size;
    arr[size + 1];
    int prev[size + 1], lp[size + 1];
    lp[0] = prev[0] = -1;
    for (i = 1; i <= size; i++)
    {
        cin >> arr[i];
        lp[i] = prev[i] = -1;
    }
    vector<int> l;
    l.push_back(arr[0]);

    for (i = 1; i <= size; i++)
    {
        if (arr[i] > l.back())
        {
            l.push_back(arr[i]);
            lp[l.size() - 1] = i;
            prev[i] = lp[l.size() - 2];
        }
        else
        {
            int idx = lower_bound(l.begin(), l.end(), arr[i]) - l.begin();
            l[idx] = arr[i];
            lp[idx] = i;
            prev[i] = lp[idx - 1];
        }
    }

    printf("Longest increasing subsequence:");
    printLIS(prev, lp[l.size() - 1]);
    cout << endl;
    return 0;
}
void printLIS(int *prev, int index)
{
    if (index == -1)
        return;
    printLIS(prev, prev[index]);
    cout << arr[index] << " ";
}