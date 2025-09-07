#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
struct Node{
    ll total,pref,suff,sum;
    Node(){}
    Node(ll total,ll pref,ll suff,ll sum){
        this->sum = sum;
        this->pref = pref;
        this->suff = suff;
        this->total = total;
    }
};
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<ll> arr(n);
    vector<Node> tree(4 * n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    function<void(int,int,int)> init = [&](int node,int l,int r) -> void{
        if(l == r){
            tree[node] = Node(arr[l],arr[l],arr[l],arr[l]);
            return;
        }
        int mid = (l + r)/2;
        init(node * 2 + 1,l,mid);
        init(node * 2 + 2,mid + 1,r);
        ll total = tree[node * 2 + 1].total + tree[node * 2 + 2].total;
        ll pref = max(tree[node * 2 + 1].pref,tree[node * 2 + 1].total + tree[node * 2 + 2].pref);
        ll suff = max(tree[node * 2 + 2].suff,tree[node * 2 + 2].total + tree[node * 2 + 1].suff);
        ll sum = max({tree[node * 2 + 1].sum,tree[node * 2 + 2].sum,tree[node * 2 + 1].suff + tree[node * 2 + 2].pref});
        tree[node] = Node(total,pref,suff,sum);
    };
    function<void(int,int,int,int,ll)> update = [&](int node,int l,int r,int indx,ll val) -> void{
        if(indx < l || r < indx) return;
        if(l == r){
            tree[node] = Node(val,val,val,val);
            return;
        }
        int mid = (l + r)/2;
        if(indx <= mid){
            update(node * 2 + 1,l,mid,indx,val);
        }
        else{
            update(node * 2 + 2,mid + 1,r,indx,val);
        }
        ll total = tree[node * 2 + 1].total + tree[node * 2 + 2].total;
        ll pref = max(tree[node * 2 + 1].pref,tree[node * 2 + 1].total + tree[node * 2 + 2].pref);
        ll suff = max(tree[node * 2 + 2].suff,tree[node * 2 + 2].total + tree[node * 2 + 1].suff);
        ll sum = max({tree[node * 2 + 1].sum,tree[node * 2 + 2].sum,tree[node * 2 + 1].suff + tree[node * 2 + 2].pref});
        tree[node] = Node(total,pref,suff,sum);
    };
    // function<Node(int,int,int,int,int)> query = [&](int node,int ql,int qr,int l,int r) -> Node{
    //     if(qr < l || r < ql) return Node(0LL,0LL,0LL,0LL);
    //     if(ql <= l && r <= qr) return tree[node];
    //     int mid = (l + r)/2;
    //     auto left = query(node * 2 + 1,ql,qr,l,mid);
    //     auto right = query(node * 2 + 2,ql,qr,mid + 1,r);
    //     ll total = left.total + right.total;
    //     ll pref = max(left.pref,left.total + right.pref);
    //     ll suff = max(right.suff,right.total + left.suff);
    //     ll sum = max({left.sum,right.sum,left.suff + right.pref});
    //     return Node(total,pref,suff,sum);
    // };
    init(0,0,n - 1);
    for(int i = 0;i < m;i++){
        int indx;
        ll val;
        cin >> indx >> val;
        indx--;
        update(0,0,n - 1,indx,val);
        cout<< max(tree[0].sum,0LL) << endl;
    }
    return 0;
}