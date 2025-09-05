#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> vals;
vector<ll> tree;
vector<int> tour;
vector<int> in,out;
vector<vector<int>> grid;
void DFS(int node,int par,int& time){
    tour.push_back(node);
    in[node] = time++;
    for(int nn : grid[node]){
        if(par == nn) continue;
        DFS(nn,node,time);
    }
    out[node] = time;
}
void BuildTree(int node,int l,int r){
    if(l == r){
        tree[node] = vals[tour[l]];
        return;
    }
    int mid = (l + r) >> 1;
    int left = (node << 1) + 1;
    int right = (node << 1) + 2;
    BuildTree(left,l,mid);
    BuildTree(right,mid + 1,r);
    tree[node] = tree[left] + tree[right];
}
void update(int node,int indx,ll val,int l,int r){
    if(indx < l || r < indx) return;
    if(l == r){
        tree[node] = val;
        return;
    }
    int mid = (l + r) >> 1;
    int left = (node << 1) + 1;
    int right = (node << 1) + 2;
    if(indx <= mid){
        update(left,indx,val,l,mid);
    }
    else{
        update(right,indx,val,mid + 1,r);
    }
    tree[node] = tree[left] + tree[right];
}
ll query(int node,int ql,int qr,int l,int r){
    if(qr < l || r < ql) return 0;
    if(ql <= l && r <= qr) return tree[node];
    int mid = (l + r) >> 1;
    int left = (node << 1) + 1;
    int right = (node << 1) + 2;
    return query(left,ql,qr,l,mid) + query(right,ql,qr,mid + 1,r);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    grid.resize(n + 1);
    vals.resize(n + 1);
    in.resize(n + 1);
    out.resize(n + 1);
    for(int i = 1;i <= n;i++){
        cin >> vals[i];
    }
    for(int i = 0;i < n - 1;i++){
        int a,b;
        cin >> a >> b;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }
    int time = 0;
    DFS(1,-1,time);
    int len = tour.size();
    tree.resize(len * 4);
    BuildTree(0,0,len - 1);
    unordered_map<int,int> map;
    for(int i = 0;i < len;i++){
        map[tour[i]] = i;
    }
    for(int i = 0;i < m;i++){
        int a,b,c;
        cin >> a >> b;
        if(a == 1){
            cin >> c;
            update(0,map[b],c,0,len - 1);
        }
        else{
            cout<< query(0,in[b],out[b] - 1,0,len - 1) << endl;
        }
    }
    return 0;
}