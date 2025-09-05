#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> tree;
void BuiltForMin(vector<int>& arr,int node,int l,int r){
    if(l == r){
        tree[node] = {arr[l],1};
        return;
    }
    int mid = (l + r) >> 1;
    BuiltForMin(arr,(node << 1) + 1,l,mid);
    BuiltForMin(arr,(node << 1) + 2,mid + 1,r);
    auto left = tree[(node << 1) + 1];
    auto right = tree[(node << 1) + 2];
    if(left.first < right.first) tree[node] = left;
    else if(left.first > right.first) tree[node] = right;
    else tree[node] = {left.first,left.second + right.second};
}
void update(int node,int l,int r,int indx,int val){
    if(l == r){
        tree[node] = {val,1};
        return;
    }
    int mid = (l + r) >> 1;
    if(indx <= mid){
        update((node << 1) + 1,l,mid,indx,val);
    }
    else{
        update((node << 1) + 2,mid + 1,r,indx,val);
    }
    auto left = tree[(node << 1) + 1];
    auto right = tree[(node << 1) + 2];
    if(left.first < right.first) tree[node] = left;
    else if(left.first > right.first) tree[node] = right;
    else tree[node] = {left.first,left.second + right.second};
}
pair<int,int> querymin(int node,int l,int r,int L,int R){
    if(r < L || R < l){
        return {INT_MAX,INT_MAX};
    }
    if(l <= L && R <= r) return tree[node];
    int mid = (L + R) >> 1;
    auto left = querymin((node << 1) + 1,l,r,L,mid);
    auto right = querymin((node << 1) + 2,l,r,mid + 1,R);
    if(left.first < right.first) return left;
    else if(left.first > right.first) return right;
    else return {left.first, left.second + right.second};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    tree.resize(4 * n);
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    BuiltForMin(arr,0,0,n-1);
    for(int i = 0;i < m;i++){
        int p,q,r;
        cin >> p >> q >> r;
        if(p == 1){
            update(0,0,n - 1,q,r);
        }
        else{
            auto res = querymin(0,q,r - 1,0,n - 1);
            cout<< res.first <<" "<<res.second << endl;
        }
    }
    return 0;
}