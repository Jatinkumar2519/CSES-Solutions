#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1),trans(n + 1);
    for(int i = 0;i < m;i++){
        int u,v;
        cin >> u >> v;
        
        graph[u].push_back(v);
        trans[v].push_back(u);
    }

    stack<int> s;
    vector<bool> visited(n + 1,false);
    function<void(int)> dfs = [&](int node)->void{
        if(visited[node]) return;

        visited[node] = true;
        for(int nn : graph[node]){
            dfs(nn);
        }
        s.push(node);
    };

    for(int node = 1;node <= n;node++){
        if(!visited[node]){
            dfs(node);
        }
    }
    
    graph = trans;
    vector<int> ids(n + 1);
    visited = vector<bool>(n + 1,false);

    function<void(int,int)> solve = [&](int node,int id){
        if(visited[node]) return;

        visited[node] = true;
        ids[node] = id;
        for(int nn : graph[node]){
            solve(nn,id);
        }
    };

    int id = 1;
    while(!s.empty()){
        int node = s.top();s.pop();

        if(visited[node]) continue;

        solve(node,id);
        id++;
    }

    cout<< id - 1 << endl;
    for(int i = 1;i <= n;i++){
        cout<< ids[i] << ' ';
    }
    return 0;
}