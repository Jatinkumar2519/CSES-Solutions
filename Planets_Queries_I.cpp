#include <bits/stdc++.h>
using namespace std;

static const int LOG = 60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> next(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> next[i];
    }

    // up[j][i] = node reached from i after 2^j steps
    vector<vector<int>> up(LOG, vector<int>(n + 1));

    // base case
    for (int i = 1; i <= n; i++) {
        up[0][i] = next[i];
    }

    // build table
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            up[j][i] = up[j - 1][ up[j - 1][i] ];
        }
    }

    // answer queries
    while (q--) {
        int node;
        long long k;
        cin >> node >> k;

        for (int j = 0; j < LOG; j++) {
            if (k & (1LL << j)) {
                node = up[j][node];
            }
        }

        cout << node << '\n';
    }

    return 0;
}
