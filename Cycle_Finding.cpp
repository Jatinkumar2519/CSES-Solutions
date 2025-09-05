#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    vector<ll> dp(n + 1, LLONG_MAX);
    vector<int> parent(n + 1, -1);
    vector<ll> visit(n + 1, 0);
    bool flag = false;
    int start = -1;

    pq.push({0, 1});
    dp[1] = 0;

    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        ll cost = p.first;
        ll node = p.second;

        if (++visit[node] >= n) {
            start = node;
            flag = true;
            break;
        }

        if (dp[node] < cost) continue;

        for (auto &temp : graph[node]) {
            if (dp[temp.first] > cost + temp.second) {
                parent[temp.first] = node;
                dp[temp.first] = cost + temp.second;
                pq.push({dp[temp.first], temp.first});
            }
        }
    }

    if (flag) {
        cout << "YES\n";
        vector<int> path;
        int end = start;
        path.push_back(end);
        start = parent[end];

        unordered_set<int> visited;
        visited.insert(end);

        while (start != -1 && visited.find(start) == visited.end()) {
            path.push_back(start);
            visited.insert(start);
            start = parent[start];
        }

        if (start == -1) {
            cout << "NO\n"; // fallback if no cycle traced properly
            return 0;
        }

        path.push_back(start);
        reverse(path.begin(), path.end());

        auto it = find(path.begin(), path.end(), start);
        path = vector<int>(it, path.end());

        for (int i : path) {
            cout << i << ' ';
        }
    } else {
        cout << "NO";
    }

    return 0;
}
