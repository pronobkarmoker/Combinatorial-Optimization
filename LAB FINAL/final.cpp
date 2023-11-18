#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int findParent(vector<int>& parent, int i) {
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}

void unionSets(vector<int>& parent, int x, int y) {
    int xSet = findParent(parent, x);
    int ySet = findParent(parent, y);
    parent[xSet] = ySet;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> chocolates(n);
    vector<int> parent(n, -1);

    for (int i = 0; i < n; ++i) {
        cin >> chocolates[i];
    }

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        unionSets(parent, x - 1, y - 1);
    }

    vector<int> totalChocolatesInGroup(n, 0);

    for (int i = 0; i < n; ++i) {
        int group = findParent(parent, i);
        totalChocolatesInGroup[group] += chocolates[i];
    }

    int result = accumulate(totalChocolatesInGroup.begin(), totalChocolatesInGroup.end(), 0);

    cout << result << endl;

    return 0;
}
