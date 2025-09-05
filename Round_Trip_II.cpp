#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> state, parent;
int cycle_start = -1, cycle_end = -1;

bool dfs(int u) {
    state[u] = 1; // currently visiting
    for (int v : graph[u]) {
        if (state[v] == 0) {
            parent[v] = u;
            if (dfs(v)) return true;
        } 
        else if (state[v] == 1) { 
            cycle_start = v;
            cycle_end = u;
            return true;
        }
    }
    state[u] = 2;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    graph.assign(n + 1, {});
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    state.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    for (int i = 1; i <= n; i++) {
        if (state[i] == 0 && dfs(i)) break;
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << "\n";
        for (int v : cycle) cout << v << " ";
        cout << "\n";
    }
    return 0;
}
