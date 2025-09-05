#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> solve(vector<vector<pair<ll,ll>>>& grid,int n,int s){
    vector<ll> dp(n + 1,LLONG_MAX);
    priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> pq;
    pq.push({0,s});
    dp[s] = 0;
    while(!pq.empty()){
        auto temp = pq.top();pq.pop();
        ll cost = temp[0];
        ll node = temp[1];
        if(dp[node] < cost) continue;
        for(auto& pair : grid[node]){
            ll newcost = cost + pair.second;
            if(dp[pair.first] > newcost){
                dp[pair.first] = newcost;
                pq.push({newcost,pair.first});
            }
        }
    }
    return dp;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> grid1(n + 1),grid2(n + 1);
    vector<vector<ll>> edges;
    for(int i = 0;i < m;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        edges.push_back({a,b,c});
        grid1[a].push_back({b,c});
        grid2[b].push_back({a,c});
    }
    vector<ll> prefix = solve(grid1,n,1);
    vector<ll> sufix = solve(grid2,n,n);
    ll mind = LLONG_MAX;
    for(auto& edge : edges){
        ll p = (prefix[edge[0]] == LLONG_MAX) ? 0 : prefix[edge[0]];
        ll s = (sufix[edge[1]] == LLONG_MAX) ? 0 : sufix[edge[1]];
        mind = min(mind,p + edge[2]/2 + s);
    }
    cout<< mind;
    return 0;
}