#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n,m) resize(n,m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;
const int MOD = 1e9 + 7;
long long powmod(long long a,long long b){
    long long res = 1;
    while(b > 0){
        if(b & 1){
           res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b = (b >> 1);
    }
    return res;
}
vl sizes;
vvi grid;
ll DFS(int node,int par){
    ll s = 1;
    for(int nn : grid[node]){
        if(nn == par) continue;
        s += DFS(nn,node);
    }
    return sizes[node] = s;
}
void solve(int node,int par,ll total,ll target,int& res){
    ll maxv = total - sizes[node];
    for(int nn : grid[node]){
        if(par == nn) continue;
        solve(nn,node,total,target,res);
        maxv = max(maxv,sizes[nn]);
    }
    if(maxv <= target){
        res = node;
        return;
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    grid.resize(n + 1);
    sizes.resize(n + 1);
    for(int i = 0;i < n - 1;i++){
        int a,b;
        cin >> a >> b;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }
    DFS(1,-1);
    int res;
    solve(1,-1,sizes[1],sizes[1]/2,res);
    cout<< res;
    return 0;
}