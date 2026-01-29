#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = LLONG_MAX / 4;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,ll>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    // ---------- Dijkstra ----------
    vector<ll> dp(n + 1, INF), routes(n + 1, 0);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;

    dp[1] = 0;
    routes[1] = 1;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();
        if (cost > dp[u]) continue;

        for (auto [v, w] : graph[u]) {
            if (dp[v] > cost + w) {
                dp[v] = cost + w;
                routes[v] = routes[u];
                pq.push({dp[v], v});
            }
            else if (dp[v] == cost + w) {
                routes[v] = (routes[v] + routes[u]) % MOD;
            }
        }
    }

    // ---------- Build shortest-path DAG ----------
    vector<vector<int>> dag(n + 1);
    vector<int> indeg(n + 1, 0);

    for (int u = 1; u <= n; u++) {
        for (auto [v, w] : graph[u]) {
            if (dp[u] + w == dp[v]) {
                dag[u].push_back(v);
                indeg[v]++;
            }
        }
    }

    // ---------- Topo order (reachable from 1 only) ----------
    queue<int> q;
    vector<int> topo;

    q.push(1);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : dag[u]) {
            if (--indeg[v] == 0)
                q.push(v);
        }
    }

    // ---------- Min edges ----------
    vector<ll> mn(n + 1, INF);
    mn[1] = 0;

    for (int u : topo) {
        for (int v : dag[u]) {
            if (mn[u] != INF)
                mn[v] = min(mn[v], mn[u] + 1);
        }
    }

    // ---------- Max edges ----------
    vector<ll> mx(n + 1, -INF);
    mx[1] = 0;

    for (int u : topo) {
        for (int v : dag[u]) {
            if (mx[u] != -INF)
                mx[v] = max(mx[v], mx[u] + 1);
        }
    }

    cout << dp[n] << " " << routes[n] << " " << mn[n] << " " << mx[n];
    return 0;
}
