#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

struct SegmentTree
{
    vector<long long> tree;
    SegmentTree(vector<int> &arr, int n)
    {
        tree.resize(n * 4);
        builtTree(arr, 0, 0, n - 1);
    }
    long long merge(long long num1, long long num2)
    {
        return min(num1,num2);
    }
    void builtTree(vector<int> &arr, int node, int l, int r)
    {
        if (r == l)
        {
            tree[node] = arr[r];
            return;
        }
        int mid = (r + l) >> 1;
        builtTree(arr, (node << 1) + 1, l, mid);
        builtTree(arr, (node << 1) + 2, mid + 1, r);
        tree[node] = merge(tree[(node << 1) + 1], tree[(node << 1) + 2]);
    }
    long long query(int node, int l, int r, int L, int R)
    {
        if (r < L || l > R)
            return LLONG_MAX;
        if (l <= L && R <= r)
            return tree[node];
        int mid = (L + R) >> 1;
        return merge(query((node << 1) + 1, l, r, L, mid), query((node << 1) + 2, l, r, mid + 1, R));
    }
    void update(int node, int L, int R, int indx, ll val)
    {
        if (L == R)
        {
            tree[node] = val;
            return;
        }
        int mid = (L + R) >> 1;
        if (indx <= mid)
        {
            update(node * 2 + 1, L, mid, indx, val);
        }
        else
        {
            update(node * 2 + 2, mid + 1, R, indx, val);
        }
        tree[node] = merge(tree[(node << 1) + 1], tree[(node << 1) + 2]);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    SegmentTree seg(arr, n);

    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            int indx;
            ll val;
            cin >> indx >> val;
            seg.update(0, 0, n - 1, indx - 1, val);
        }
        else
        {
            int l,r;
            cin >> l >> r;
            cout << seg.query(0,l - 1, r - 1,0,n - 1) << endl;
        }
    }
    return 0;
}