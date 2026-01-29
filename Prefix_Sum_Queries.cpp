#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
struct SegmentTree
{
    vector<pair<ll,ll>> tree;
    SegmentTree(int n,vector<ll>& arr){
        tree.resize(4 * n);
        buildTree(arr,0,0,n - 1);
    }
    void buildTree(vector<ll>& arr,int node,int l,int r){
        if(l == r){
            tree[node] = {arr[l],arr[l]};
            return;
        }
        int mid = (l + r)/2;
        int left = node * 2 + 1;
        int right = node * 2 + 2;
        buildTree(arr,left,l,mid);
        buildTree(arr,right,mid + 1,r);
        tree[node].first = max({tree[left].first,tree[left].second,tree[left].second + tree[right].first,tree[left].second + tree[right].second});
        tree[node].second = tree[left].second + tree[right].second;
    }
    void update(int node,int indx,ll val,int l,int r){
        if(indx < l || r < indx) return;
        if(l == r){
            tree[node] = {val,val};
            return;
        }
        int mid = (l + r)/2;
        int left = node * 2 + 1;
        int right = node * 2 + 2;
        if(indx <= mid){
            update(left,indx,val,l,mid);
        }
        else{
            update(right,indx,val,mid + 1,r);
        }
        tree[node].first = max({tree[left].first,tree[left].second,tree[left].second + tree[right].first,tree[left].second + tree[right].second});
        tree[node].second = tree[left].second + tree[right].second;
    }
    pair<ll,ll> query(int node,int ql,int qr,int l,int r){
        if(qr < l || r < ql) return {0,0};
        if(ql <= l && r <= qr) return tree[node];
        int mid = (l + r)/2;
        auto left = query(node * 2 + 1,ql,qr,l,mid);
        auto right = query(node * 2 + 2,ql,qr,mid + 1,r);
        return {max({left.first,left.second,left.second + right.first,left.second + right.second}),left.second + right.second};
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<ll> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    SegmentTree seg(n,arr);
    for(int i = 0;i < m;i++){
        int t;
        cin >> t;
        if(t == 1){
            int indx;
            ll val;
            cin >> indx >> val;
            indx --;
            seg.update(0,indx,val,0,n - 1);
        }
        else{
            int l,r;
            cin >> l >> r;
            l--;r--;
            auto res = seg.query(0,l,r,0,n - 1);
            cout<< max({res.first,res.second,0LL}) << endl;
        }
    }
    return 0;
}