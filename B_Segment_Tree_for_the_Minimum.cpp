#include <bits/stdc++.h>
using namespace std;
struct SegmentTree{
    vector<long long> tree;
    SegmentTree(vector<int>& arr,int n){
        tree.resize(n * 4);
        builtTree(arr,0,0,n - 1);
    }
    void builtTree(vector<int>& arr,int node,int l,int r){
        if(r == l){
            tree[node] = arr[r];
            return;
        }
        int mid = (r + l) >> 1;
        builtTree(arr,(node << 1) + 1,l,mid);
        builtTree(arr,(node << 1) + 2,mid + 1,r);
        tree[node] = min(tree[(node << 1) + 1] , tree[(node << 1) + 2]);
    }
    int query(int node,int l,int r,int L,int R){
        if(r < L || l > R) return INT_MAX;
        if(l <= L && R <= r) return tree[node];
        int mid = (L + R) >> 1;
        return min(query((node << 1) + 1,l,r,L,mid) , query((node << 1) + 2,l,r,mid + 1,R));
    }
    void update(int node,int L,int R,int indx,int val){
        if(L == R){
            tree[node] = val;
            return;
        }
        int mid = (L + R) >> 1;
        if(indx <= mid){
            update(node * 2 + 1,L,mid,indx,val);
        }
        else{
            update(node * 2 + 2,mid + 1,R,indx,val);
        }
        tree[node] = min(tree[(node << 1) + 1] , tree[(node << 1) + 2]);
    }
};
int main() {
    int n,m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    SegmentTree code = SegmentTree(arr,n);
    for(int i = 0;i < m;i++){
        int p,q,r;
        cin >> p >> q >> r;
        if(p == 1){
            code.update(0,0,n - 1,q,r);
        }
        else{
            cout<< code.query(0,q,r - 1,0,n - 1) << endl;
        }
    }
    return 0;
}