#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n,m) resize(n,m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;
const int MOD = 1e9 + 7;
vvi graph;
void dfs1(int node,int par,int len,int& maxlen,int& end1){
    if(maxlen < len){
        len = maxlen;
        end1 = node;
    }
    for(int nn : graph[node]){
        if(nn == par) continue;
        dfs1(nn,node,len + 1,maxlen,end1);
    }
}
void solve(int node,int par,int len,vector<int>& dist){
    dist[node] = len;
    for(int nn : graph[node]){
        if(par == nn) continue;
        solve(nn,node,len + 1,dist);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    graph.resize(n + 1);
    for(int i = 0;i < n - 1;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int end1,end2;
    int maxlen = 0;
    dfs1(1,-1,0,maxlen,end1);
    maxlen = 0;
    dfs1(end1,-1,0,maxlen,end2);
    vector<int> dist1(n + 1,INT_MAX),dist2(n + 1,INT_MAX);
    solve(end1,-1,0,dist1);
    solve(end2,-1,0,dist2);
    for(int i = 0;i < m;i++){
        int l;
        cin >> l;
        vector<int> arr(l);
        for(int j = 0;j < l;j++){
            cin >> arr[j];
        }
        vector<int> dist(n + 1);
        for(int nn : arr){
            
        }
        int maxv = 0;
        for(int i = 1;i <= n;i++){
           
        }
        cout<< maxv << endl;
    }
    return 0;
}