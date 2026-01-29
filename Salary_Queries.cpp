#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;


struct SegmentTree
{
    vector<long long> tree;
    SegmentTree(int n)
    {
        tree.resize(n * 4);
    }
    long long merge(long long num1, long long num2)
    {
        return num1 + num2;
    }
    long long query(int node, int l, int r, int L, int R)
    {
        if (r < L || l > R)
            return 0;
        if (l <= L && R <= r)
            return tree[node];
        int mid = (L + R) >> 1;
        return merge(query((node << 1) + 1, l, r, L, mid), query((node << 1) + 2, l, r, mid + 1, R));
    }
    void update(int node, int L, int R, int indx,int val)
    {
        if (L == R)
        {
            tree[node] += val;
            return;
        }
        int mid = (L + R) >> 1;
        if (indx <= mid)
        {
            update(node * 2 + 1, L, mid, indx,val);
        }
        else
        {
            update(node * 2 + 2, mid + 1, R, indx,val);
        }
        tree[node] = merge(tree[(node << 1) + 1], tree[(node << 1) + 2]);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n,m;
    cin >> n >> m;
    
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    set<int> sorted(arr.begin(),arr.end());

    int l = sorted.size();
    vector<int> nums(sorted.begin(),sorted.end());

    unordered_map<int,int> index;
    for(int i = 0;i < l;i++){
        index[nums[i]] = i;
    }

    SegmentTree seg(l);
    for(int i = 0;i < n;i++){
        int idx = index[arr[i]];

        seg.update(0,0,n - 1,idx,1);
    }

    for(int i = 0;i < m;i++){
        char t;
        cin >> t;
        if(t == '!'){
            int idx,val;
            cin >> idx >> val;
            
        }
    }
    return 0;
}