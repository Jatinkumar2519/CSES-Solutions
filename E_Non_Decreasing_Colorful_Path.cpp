#include <bits/stdc++.h>
#define ll long long
using namespace std;
int dp[200001];
int vis[200001];
int solve(vector<vector<int>> &grid, int node, int n, vector<ll> &val)
{
    if (node == n)
        return 0;
    if (dp[node] != -1)
        return dp[node];

    int res = 0;
    bool found = false;  

    vis[node] = 1;
    for (int nn : grid[node])
    {
        if (vis[nn]) continue;

        int temp = INT_MIN;
        if (val[node] < val[nn])
            temp = solve(grid, nn, n, val);
        else if (val[node] == val[nn])
            temp = solve(grid, nn, n, val);

        if (temp != INT_MIN) {
            found = true;
            if (val[node] < val[nn])
                res = max(res, 1 + temp);
            else
                res = max(res, temp);
        }
    }
    vis[node] = 0;

    return dp[node] = (found ? res : INT_MIN);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    vector<ll> val(n + 1);
    vector<vector<int>> graph(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int res = solve(graph, 1, n, val);
    if(res == INT_MIN) cout<< 0;
    else cout<< res + 1;
    return 0;
}