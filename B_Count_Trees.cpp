#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(m, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            char ch;
            cin >> ch;
            if (ch == '*') {
                grid[i][j] = 1;
            }
        }
    }

    // Build 2D prefix sum
    vector<vector<int>> prefix(m, vector<int>(m, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            prefix[i][j] = grid[i][j];
            if (i > 0) prefix[i][j] += prefix[i - 1][j];
            if (j > 0) prefix[i][j] += prefix[i][j - 1];
            if (i > 0 && j > 0) prefix[i][j] -= prefix[i - 1][j - 1];
        }
    }

    // Answering queries in O(1)
    for (int k = 0; k < n; k++) {
        int x, y, p, q;
        cin >> x >> y >> p >> q;
        x--, y--, p--, q--;

        int total = prefix[p][q];
        if (x > 0) total -= prefix[x - 1][q];
        if (y > 0) total -= prefix[p][y - 1];
        if (x > 0 && y > 0) total += prefix[x - 1][y - 1];

        cout << total << endl;
    }

    return 0;
}
