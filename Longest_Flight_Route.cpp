#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n,m) resize(n,m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for(int i = 0;i < m;i++){
        int u ,v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    vector<int> dist(n + 1,0);
    vector<int> parent(n + 1,-1);
    priority_queue<pair<int,int>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto [cost,node] = pq.top();pq.pop();
        if(dist[node] > cost) continue;
        for(auto nn : graph[node]){
            if(dist[nn] < cost + 1){
                dist[nn] = cost + 1;
                parent[nn] = node;
                pq.push({cost + 1,nn});
            }
        }
    }
    if(dist[n] == 0){
        cout<< "IMPOSSIBLE";
    }
    else{
        vector<int> path;
        for(int node = n;node != -1 && node > 0;node = parent[node]){
            path.push_back(node);
        }
        reverse(path.begin(),path.end());
        cout<< path.size() << endl;
        for(auto node : path){
            cout<< node << ' ';
        }
    }
    return 0;
}