#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
vector<ll> sizes;
vector<vector<int>> grid;
int dfs(int node,int par){
    ll s = 1;
    for(int nn : grid[node]){
        if(nn == par) continue;
        s += dfs(nn,node);
    }
    sizes[node] = s;
    return s;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    grid.resize(n + 1);
    sizes.resize(n + 1,0);
    for(int i = 2;i <= n;i++){
        int a;
        cin >> a;
        grid[a].push_back(i);
        grid[i].push_back(a);
    }
    dfs(1,-1);
    for(int i = 1;i <= n;i++){
        cout<< sizes[i] - 1<< ' ';
    }
    return 0;
}