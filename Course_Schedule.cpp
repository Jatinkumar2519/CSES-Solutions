#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> degree(n + 1,0);
    vector<vector<int>> graph(n + 1);
    for(int i = 0;i < m;i++){
        int u,v;
        cin >> u >> v;
        degree[v]++;
        graph[u].push_back(v);
    }
    queue<int> q;
    for(int i = 1;i <= n;i++){
        if(degree[i] == 0){
            q.push(i);
        }
    }
    int count = 0;
    vector<int> res;
    while(!q.empty()){
        count++;
        int node = q.front();q.pop();
        res.push_back(node);
        for(int nn : graph[node]){
            if(--degree[nn] == 0){
                q.push(nn);
            }
        }
    }
    if(count != n){
        cout<< "IMPOSSIBLE" ;
    }
    else{
        for(int i : res){
            cout<< i << ' ';
        }
    }
    return 0;
}