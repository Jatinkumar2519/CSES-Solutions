#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<array<ll,3>> edges;
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    vector<ll> dp(n + 1, 0);
    vector<int> parent(n + 1, -1);

    int start = -1;

    for (int i = 0; i < n; i++) {
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            ll d = e[2];
            if (dp[v] > dp[u] + d) {
                dp[v] = dp[u] + d;
                parent[v] = u;
                if (i == n - 1) {
                    start = v;
                }
            }
        }
    }

    if (start == -1) {
        cout << "NO\n";
        return 0;
    }

    int x = start;
    for (int i = 0; i < n; i++) {
        x = parent[x];
    }

    vector<int> cycle;
    int cur = x;
    do {
        cycle.push_back(cur);
        cur = parent[cur];
    } while (cur != x);
    cycle.push_back(x);
    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    for (int v : cycle) cout << v << " ";
    cout << "\n";

    return 0;
}
