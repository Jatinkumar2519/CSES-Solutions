#include <bits/stdc++.h>
# define ll long long
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,ll>>> grid(n + 1);
    for(int i = 0;i < m;i++){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        grid[a].push_back({b,c});
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    vector<ll> dist(n + 1,LLONG_MAX);
    dist[1] = 0;
    pq.push({0,1});
    while(!pq.empty()){
        auto temp = pq.top();pq.pop();
        ll path = temp.first;
        int node = temp.second;
        if(dist[node] < path) continue;
        for(auto& pair : grid[node]){
            if(dist[pair.first] > path + pair.second){
                dist[pair.first] = path + pair.second;
                pq.push({path + pair.second,pair.first});
            }
        }
    } 
    for(int i = 1;i <= n;i++){
        cout<< dist[i] << ' ';
    }
    return 0;
}