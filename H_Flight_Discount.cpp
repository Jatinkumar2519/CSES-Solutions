#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n,m) resize(n,m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;
const int MOD = 1e9 + 7;
// long long powmod(long long a,long long b){
//     long long res = 1;
//     while(b > 0){
//         if(b & 1){
//            res = (res * a) % MOD;
//         }
//         a = (a * a) % MOD;
//         b = (b >> 1);
//     }
//     return res;
// }
void solve(vector<vector<pair<int,ll>>>& grid,int strt,vector<ll>& dist){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push({0,strt});
    dist[strt] = 0;
    while(!pq.empty()){
        auto temp = pq.top();pq.pop();
        ll len = temp.first;
        int node = temp.second;
        if(dist[node] < len) continue;
        for(auto nnp : grid[node]){
            int nn = nnp.first;
            ll l = nnp.second;
            ll newdist = len + l;
            if(dist[nn] > newdist){
                dist[nn] = newdist;
                pq.push({newdist,nn});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,ll>>> grid1(n + 1),grid2(n + 1);
    vector<tuple<int,int,ll>>edges;
    for(int i = 0;i < m;i++){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        grid1[a].push_back({b,c});
        grid2[b].push_back({a,c});
        edges.push_back({a,b,c});
    }
    vector<ll> dist1(n + 1,LLONG_MAX),dist2(n + 1,LLONG_MAX);
    solve(grid1,1,dist1);
    solve(grid2,n,dist2);
    ll minv = LLONG_MAX;
    for(auto edge : edges){
        int a = get<0>(edge);
        int b = get<1>(edge);
        ll  c = get<2>(edge);
        ll pre = (dist1[a] == LLONG_MAX) ? 0 : dist1[a];
        ll suf = (dist2[b] == LLONG_MAX) ? 0 : dist2[b];
        minv = min(minv,pre + suf + c / 2);
    }
    cout<< minv;
    return 0;
}