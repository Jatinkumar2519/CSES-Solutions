#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n), arr(n);
    for(int i=0;i<n;i++) cin >> nums[i];
    for(int i=0;i<n;i++) cin >> arr[i];

    vector<int> tree(4*n);

    function<void(int,int,int)> build = [&](int node,int l,int r){
        if(l==r){
            tree[node] = 1;
            return;
        }
        int mid=(l+r)/2;
        build(node*2+1,l,mid);
        build(node*2+2,mid+1,r);
        tree[node] = tree[node*2+1] + tree[node*2+2];
    };

    function<void(int,int,int,int)> update = [&](int node,int l,int r,int idx){
        if(idx<l || idx>r) return;
        if(l==r){
            tree[node] = 0;
            return;
        }
        int mid=(l+r)/2;
        update(node*2+1,l,mid,idx);
        update(node*2+2,mid+1,r,idx);
        tree[node] = tree[node*2+1] + tree[node*2+2];
    };

    function<int(int,int,int,int)> findKth = [&](int node,int l,int r,int k){
        if(tree[node] < k) return -1;
        if(l==r) return l;
        int mid=(l+r)/2;
        int leftCount = tree[node*2+1];
        if(k <= leftCount) return findKth(node*2+1,l,mid,k);
        return findKth(node*2+2,mid+1,r,k-leftCount);
    };

    build(0,0,n-1);

    for(int i=0;i<n;i++){
        int idx = findKth(0,0,n-1,arr[i]);
        if(idx==-1){
            cout << -1 << ' ';
        }else{
            cout << nums[idx] << ' ';
            update(0,0,n-1,idx);
        }
    }
    return 0;
}
