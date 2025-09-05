#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid;
void dfs(int node,int par,int len,int& end,int& maxlen){
    if(len > maxlen){
        maxlen = len;
        end = node;
    }
    for(int nn : grid[node]){
        if(nn == par) continue;
        dfs(nn,node,len + 1,end,maxlen);
    }
}
void solve(int node,int par,int len,vector<int>& dist){
    dist[node] = len;
    for(int nn : grid[node]){
        if(nn == par) continue;
        solve(nn,node,len + 1,dist);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    grid.resize(n + 1);
    for(int i = 0;i < n - 1;i++){
        int a,b;
        cin >> a >> b;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }
    int end1 = 1;
    int maxlen = 0;
    dfs(1,-1,0,end1,maxlen);
    int end2 = end1;
    maxlen = 0;
    dfs(end1,-1,0,end2,maxlen);
    vector<int> dist1(n + 1,0),dist2(n + 1,0);
    solve(end1,-1,0,dist1);
    solve(end2,-1,0,dist2);
    for(int i = 1;i <= n;i++){
        cout<< max(dist1[i],dist2[i]) << ' ';
    }
    return 0;
}