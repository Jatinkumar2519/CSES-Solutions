#include <bits/stdc++.h>
# define ll long long
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    long long sum = 0;
    vector<vector<pair<int, ll>>> adj(n + 1);
    vector<int> color(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        if(color[u] != color[v]) sum += w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int i = 0; i < m; i++) {
        int a, newColor;
        cin >> a >> newColor;
        for (auto temp : adj[a]) {
            if (color[a] != color[temp.first]) {
                sum -= temp.second;
            }
        }
        color[a] = newColor;
        for (auto temp : adj[a]) {
            if (color[a] != color[temp.first]) {
                sum += temp.second;
            }
        }
        cout << sum << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
