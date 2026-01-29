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
        edges.push_back({u,v,-d});
    }

    vector<ll> dp(n + 1,LLONG_MAX);
    dp[1] = 0;

    for(int i = 1;i <= n;i++){
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int d = edge[2];
            if(dp[u] != LLONG_MAX && dp[v] > dp[u] + d){
                if(i == n){
                    cout<< -1 ;
                    return 0;
                }
                dp[v] = dp[u] + d;
            }
        }
    }
    cout<< -dp[n];
    return 0;
}
