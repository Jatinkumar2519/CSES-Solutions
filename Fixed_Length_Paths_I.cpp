#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n,m) resize(n,m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;
const int MOD = 1e9 + 7;
int n,k;
vvi grid;
ll result;
vi blocked,sizes;
int getSize(int node,int par){
    if(blocked[node]) return 0;
    sizes[node] = 1;
    for(int nn : grid[node]){
        if(par == nn) continue;
        sizes[node] += getSize(nn,node);
    }
    return sizes[node];
}
int getCentroid(int node, int par, int total) {
    for (int nn : grid[node]) {
        if (nn != par && !blocked[nn]) {
            if (sizes[nn] > total / 2) {
                return getCentroid(nn, node, total);
            }
        }
    }
    return node;
}
void getDepths(int node,int par,int depth,vector<int>& depths){
    if(blocked[node] || depth > k) return;
    depths.push_back(depth);
    for(int nn : grid[node]){
        if(nn == par) continue;
        getDepths(nn,node,depth + 1,depths);
    }
}
void solve(int node){
    int total = getSize(node,-1);
    int center = getCentroid(node,-1,total);
    unordered_map<int,int> map;
    map[0] = 1;
    blocked[center] = true;
    for(int nn : grid[center]){
        if(blocked[nn]) continue;
        vector<int> depths;
        getDepths(nn,center,1,depths);
        for(int& d : depths){
            result += map[k - d];
        }
        for(int& d : depths){
            map[d]++;
        }
    }
    for(int nn : grid[center]){
        if(!blocked[nn]){
            solve(nn);
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    result = 0;
    cin >> n >> k;
    grid.resize(n + 1);
    sizes.resize(n + 1,0);
    blocked.resize(n + 1,0);
    for(int i = 0;i < n - 1;i++){
        int a,b;
        cin >> a>> b;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }
    solve(1);
    cout<< result;
    return 0;
}