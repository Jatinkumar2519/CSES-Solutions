#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n, m) resize(n, m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;
const int MOD = 1e9 + 7;
vi arr;
struct SegmentTree
{
    vector<pair<int,set<int>>> tree;
    SegmentTree(int n,vi& arr)
    {
        tree.resize(4 * n);
        BuildTree(arr,0,0,n - 1);
    }
    void BuildTree(vi& arr,int node,int l,int r){
        if(l == r){
            set<int> set;
            set.insert(arr[l]);
            tree[node] = {1,set};
            return;
        }
        int mid = (l + r) >> 1;
        int left = (node << 1) + 1;
        int right = (node << 1) + 2;
        BuildTree(arr,left,l,mid);
        BuildTree(arr,right,mid + 1,r);
        auto set1 = tree[left].second;
        auto set2 = tree[right].second;
        if(set1.size() > set2.size()){
            for(int num : set2){
                set1.insert(num);
            }
            tree[node] = {set1.size(),set1};
        }
        else{
            for(int num : set1){
                set2.insert(num);
            }
            tree[node] = {set2.size(),set2};
        }
    }
    int query(int node,int ql,int qr,int l,int r){
        if(qr < l || r < ql) return 0;
        if(ql <= l && r <= qr){
            return tree[node].first;
        }
        int mid = (l + r) >> 1;
        int left = (node << 1) + 1;
        int right = (node << 1) + 2;
        return query(left,ql,qr,l,mid) + query(right,ql,qr,mid + 1,r);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    arr.rs(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    SegmentTree code(n,arr);
    for(int i = 0;i < m;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        cout<< code.query(0,a,b,0,n - 1) << endl;
    }
    return 0;
}