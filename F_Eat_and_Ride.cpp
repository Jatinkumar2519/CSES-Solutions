#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<ll> weights(n + 1);
    for(int i = 1;i <= n;i++){
        cin >> weights[i];
    }
    vector<vector<int>> graph(n + 1);
    for(int i = 0;i < m;i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<ll> dist(n + 1,LLONG_MAX);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push({weights[1],1});
    dist[1] = weights[1];
    while(!pq.empty()){
        auto [cost,node] = pq.top();pq.pop();
        if(dist[node] < cost) continue;
        for(auto nn : graph[node]){
            if(dist[nn] > cost + weights[nn]){
                dist[nn] = cost + weights[nn];
                pq.push({dist[nn],nn});
            }
        }
    }
    for(int i = 1;i <= n;i++){
        cout<< dist[i] << endl;
    }
    return 0;
}