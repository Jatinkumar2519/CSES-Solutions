#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    vector<tuple<int,int,int>> tree(n * 4);
    auto merge = [&](tuple<int,int,int>& a,tuple<int,int,int>& b){
        if(get<1>(a) < get<1>(b)) return make_tuple(get<0>(a) + get<0>(b),get<1>(b),get<2>(b));
        if(get<1>(a) > get<1>(b)) return a;
        return make_tuple(get<0>(a) + get<0>(b),get<1>(b),get<2>(b));
    };
    function<void(int,int,int)> init = [&](int node,int l,int r)->void{
        if(l > r) return;
        if(l == r){
            tree[node] = {1,arr[l],1};
            return;
        }
        int mid = (l + r)/2;
        init(node * 2 + 1,l,mid);
        init(node * 2 + 1,mid + 1,r);
        tree[node] = merge(tree[node * 2 + 1],tree[node * 2 + 2]);
    };
    return 0;
}