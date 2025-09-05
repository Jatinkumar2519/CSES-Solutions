#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid;
vector<int> visited,parent;
int start,cycle_end;
bool solve(int node,int par){
    visited[node] = 1;
    for(int nn : grid[node]){
        if(nn == par) continue;
        if(visited[nn]){
            start = nn;
            cycle_end = node;
            return true;
        }
        else{
            parent[nn] = node;
            if(solve(nn,node)) return true;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    grid.resize(n + 1);
    visited.resize(n + 1,0);
    parent.resize(n + 1,-1);
    start = cycle_end = -1;
    for(int i = 0;i < m;i++){
        int a,b;
        cin >> a >> b;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }
    bool flag = false;
    for(int i = 1;i <= n;i++){
        if(visited[i] == 0){
            if(solve(i,-1)){
                flag = true;
                break;
            }
        }
    }
    if(!flag){ 
        cout<< "IMPOSSIBLE";
        return 0;
    }
    vector<int> path;
    for(int node = cycle_end;node != start;node = parent[node]){
        path.push_back(node);
    }
    path.push_back(start);
    path.push_back(cycle_end);
    cout<< path.size() << endl;
    for(int i : path){
        cout<< i << ' ';
    }
    return 0;
}