#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1);
    for(int i = 0;i < m;i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> parent(n + 1,-1);
    vector<int> dist(n + 1,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({1,1});
    while(!pq.empty()){
        pair<int,int> temp = pq.top();pq.pop();
        int len = temp.first;
        int node = temp.second;
        if(node == n) break;
        if(dist[node] < len) continue;
        for(int nn : graph[node]){
            if(dist[nn] > len + 1){
                dist[nn] = len + 1;
                parent[nn] = node;
                pq.push({len + 1,nn});
            }
        }
    }
    if(dist[n] != INT_MAX){
        cout<< dist[n] << endl;
        vector<int> path;
        int i = n;
        while(i != 1){
            path.push_back(i);
            i = parent[i];
        }
        path.push_back(i);
        reverse(path.begin(),path.end());
        for(int i : path){
            cout<<i<<' ';
        }
        return 0;
    }
    cout<< "IMPOSSIBLE";
    return 0;
}