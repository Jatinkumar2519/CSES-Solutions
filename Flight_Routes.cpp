#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n,m) resize(n,m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<pair<int,ll>>> graph(n + 1);
    for(int i = 0;i < m;i++){
        int u,v;
        ll d;
        cin >> u >> v >> d;
        graph[u].push_back({v,d});
    }
    vector<vector<ll>> dist(n + 1);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push({0,1});
    while(!pq.empty() && (int)dist[n].size() < k)
    {
        auto [cost,node] = pq.top();pq.pop();
        if(dist[node].size() >= k) continue;
        dist[node].push_back(cost);
        for(auto [nn,dst] : graph[node]){
            if(dist[nn].size() < k)
                pq.push({cost + dst,nn});
        }
    }
    for(auto& node : dist[n]){
        cout << node << ' ';
    }
    return 0;
}