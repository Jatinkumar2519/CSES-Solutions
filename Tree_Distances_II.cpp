#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
vector<ll> dist;
vector<ll> sizes;
vector<vector<int>> grid;
int dfs(int node,int par,int len){
    dist[0] += len;
    ll s = 1;
    for(int nn : grid[node]){
        if(nn == par) continue;
        s += dfs(nn,node,len + 1);
    }
    sizes[node] = s;
    return s;
}
void solve(int node,int par,ll total){
    dist[node] = total;
    for(int nn : grid[node]){
        if(par == nn) continue;
        solve(nn,node,total + n - 2*sizes[nn]);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    grid.resize(n + 1);
    dist.resize(n + 1,0);
    sizes.resize(n + 1,0);
    for(int i = 0;i < n - 1;i++){
        int a,b;
        cin >> a >> b;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }
    dfs(1,-1,0);
    solve(1,-1,dist[0]);
    for(int i = 1;i <= n;i++){
        cout<< dist[i] << ' ';
    }
    return 0;
}