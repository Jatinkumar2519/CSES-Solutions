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

    vector<bool> visited(n + 1,false);

    function<void(int)> dfs = [&](int node)->void{
        if(visited[node]) return;

        visited[node] = true;
        for(int nn : graph[node]){
            dfs(nn);
        }
    };

    dfs(1);

    for(int node = 1;node <= n;node++){
        if(!visited[node]){
            cout<< "NO" << endl;
            cout<< 1 << ' ' << node;
            return 0;
        }
    }

    visited = vector<bool>(n + 1,false);
    graph = trans;

    dfs(1);
    for(int node = 1;node <= n;node++){
        if(!visited[node]){
            cout<< "NO" << endl;
            cout<< node << ' ' << 1;
            return 0;
        }
    }

    cout<< "YES";
    return 0;
}