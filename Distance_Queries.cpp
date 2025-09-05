#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<pair<int,int>> tree;
vector<int> euler,height,first;
void solve(int node,int par,int len){
    height[node] = len;
    first[node] = euler.size();
    euler.push_back(node);
    for(int nn : graph[node]){
        if(par == nn) continue;
        solve(nn,node,len + 1);
        euler.push_back(node);
    }
}
void BuiltTree(int node,int l, int r){
    if(l == r){
        tree[node] = {euler[l],height[euler[l]]};
        return;
    }
    int mid = (l + r) >> 1;
    int le = (node << 1) + 1;
    int ri = (node << 1) + 2;
    BuiltTree(le,l,mid);
    BuiltTree(ri,mid + 1,r);
    if(tree[le].second < tree[ri].second){
        tree[node] = tree[le];
    }
    else{
        tree[node] = tree[ri];
    }
}
pair<int,int> query(int node,int ql,int qr,int l,int r){
    if(qr < l || r < ql) return {INT_MAX,INT_MAX};
    if(ql <= l && r <= qr){
        return tree[node];
    }
    int mid = (l + r) >> 1;
    int le = (node << 1) + 1;
    int ri = (node << 1) + 2;
    auto left = query(le,ql,qr,l,mid);
    auto right = query(ri,ql,qr,mid + 1,r);
    if(left.second < right.second){
        return left;
    }
    return right;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    graph.resize(n + 1);
    height.resize(n + 1);
    first.resize(n + 1);
    for(int i = 0;i < n - 1;i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    solve(1,-1,0);
    int e_n = euler.size();
    tree.resize(4 * e_n);
    BuiltTree(0,0,e_n - 1);
    for(int i = 0;i < m;i++){
        int a,b;
        cin >> a >> b;
        int ql = first[a];
        int qr = first[b];
        if(ql > qr){
            swap(ql,qr);
        }
        auto res = query(0,ql,qr,0,e_n - 1);
        cout<< height[a] + height[b] - 2 * res.second << endl;
    }
    return 0;
}