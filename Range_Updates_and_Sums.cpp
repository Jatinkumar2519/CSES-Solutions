#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<ll> arr(n),tree(n * 4);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    function<void(int,int,int)> init = [&](int node,int l,int r) -> void{
        if(l == r){
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r)/2;
        init(node * 2 + 1,l,mid);
        init(node * 2 + 2,mid + 1,r);
        tree[node] = tree[node * 2 + 2] + tree[node * 2 + 1];
    };
    function<void(int,int,int,int,int,ll)> inc = [&](int node,int ql,int qr,int l,int r,ll val) -> void{
        if(qr < l || r < ql) return;
        if(ql <= l && r <= qr){
            tree[node] += val;
            return;
        }
        int mid = (l + r)/2;
        inc(node * 2 + 1,ql,qr,l,mid,val);
        inc(node * 2 + 2,ql,qr,mid + 1,r,val);
        tree[node] = tree[node * 2 + 2] + tree[node * 2 + 1];
    };
    function<void(int,int,int,int,int,ll)> change = [&](int node,int ql,int qr,int l,int r,ll val) -> void{
        if(qr < l || r < ql) return;
        if(ql <= l && r <= qr){
            tree[node] = val;
            return;
        }
        int mid = (l + r)/2;
        change(node * 2 + 1,ql,qr,l,mid,val);
        change(node * 2 + 2,ql,qr,mid + 1,r,val);
        tree[node] = tree[node * 2 + 2] + tree[node * 2 + 1];
    };
    function<ll(int,int,int,int,int)> query = [&](int node,int ql,int qr,int l,int r) -> ll{
        if(qr < l || r < ql) return 0LL;
        if(ql <= l && r <= qr) return tree[node];
        int mid = (l + r)/2;
        return query(node * 2 + 1,ql,qr,l,mid) + query(node * 2 + 2,ql,qr,mid + 1,r);
    };
    init(0,0,n - 1);
    for(int i = 0;i < m;i++){
        int t;
        cin >> t;
        if(t == 1){
            int l,r;
            ll val;
            cin >> l >> r >> val;
            l--;r--;
            inc(0,l,r,0,n - 1,val);
        }
        else if(t == 2){
            int l,r;
            ll val;
            cin >> l >> r >> val;
            l--;r--;
            change(0,l,r,0,n - 1,val);
        }
        else{
             int l,r;
            cin >> l >> r;
            l--;r--;
            cout<< query(0,l,r,0,n - 1) << endl;
        }
    }
    return 0;
}