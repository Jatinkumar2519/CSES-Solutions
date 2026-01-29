#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    if (!(cin >> tt)) return 0;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (int i = 0; i < n; ++i) cin >> grid[i];

        int count = 0;
        for (int i = 0; i + 1 < n; ++i) {
            for (int j = 0; j + 1 < m; ++j) {
                if (grid[i][j] == '#' &&
                    grid[i][j+1] == '#' &&
                    grid[i+1][j] == '#' &&
                    grid[i+1][j+1] == '#') {
                    grid[i+1][j+1] = '.';
                    ++count;
                }
            }
        }
        cout << count << '\n';
    }
    return 0;
}
