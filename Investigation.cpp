#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,ll>>> graph(n + 1);
    for(int i = 0;i < m;i++){
        int u,v;
        ll d;
        cin >> u >> v >> d;
        graph[u].emplace_back(v,d);
    }
    vector<ll> result(4,-1);
    function<void()> minCost = [&]() -> void{
        vector<ll> dist(n + 1,LLONG_MAX),routes(n + 1,0);
        dist[0] = 0;
        priority_queue<tuple<ll,int,ll>,vector<tuple<ll,int,ll>>,greater<tuple<ll,int,ll>>> pq;
        pq.push({0,1,0});
        while(!pq.empty()){
            auto [cost,node,count] = pq.top();pq.pop();
            if(dist[node] < cost) continue;
            if(node == n){
                result[2] = (result[2] == -1) ? count : min(result[2],count);
                result[3] = (result[3] == -1) ? count : max(result[3],count);
            }
            if(dist[node] == cost) routes[node] = (routes[node] + 1) % MOD;
            for(auto& [nn,cst] : graph[node]){
                if(dist[nn] > cost + cst){
                    dist[nn] = cost + cst;
                    pq.push({dist[nn],nn,count + 1});
                }
            }
        }
        result[0] = dist[n];
        result[1] = routes[n];
    };
    minCost();
    for(int i : result) cout<<i<<' ';
    return 0;
}