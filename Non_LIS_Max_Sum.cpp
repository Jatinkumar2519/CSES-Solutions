#include <bits/stdc++.h>
using namespace std;
class SegmentTree{
    vector<pair<int,int>> tree;
    SegmentTree(int n){
        tree.resize(n * 4);
    }
    void update(int node,int indx,int val,int l,int r){
        if(l == r){
            tree[node] = {val,val};
        }
        if(indx < l || indx > r) return;
    }
};
int solve(){

}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    
    return 0;
}