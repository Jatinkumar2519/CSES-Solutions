#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        edges.push_back({u, v, d});
    }

    sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b)
         { return a[2] < b[2]; });

    vector<int> parent(n + 1), rankk(n + 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    function<int(int)> find = [&](int node) -> int
    {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    };

    auto Union = [&](int node1, int node2)
    {
        int p1 = find(node1);
        int p2 = find(node2);

        if (p1 == p2)
            return false;

        if (rankk[p1] > rankk[p2])
        {
            parent[p2] = p1;
        }
        else if (rankk[p1] < rankk[p2])
        {
            parent[p1] = p2;
        }
        else
        {
            rankk[p1]++;
            parent[p2] = p1;
        }
        return true;
    };

    
    ll cost = 0;
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int d = edge[2];
        
        if (Union(u, v))
        {
            cost += d;
        }
    }
    
    unordered_set<int> comp;
    for (int i = 1; i <= n; i++)
    {
        comp.insert(find(i));
    }

    if (comp.size() > 1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    
    cout << cost;
    return 0;
}
