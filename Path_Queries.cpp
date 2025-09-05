#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n, m) resize(n, m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;
const int MOD = 1e9 + 7;
// long long powmod(long long a, long long b)
// {
//     long long res = 1;
//     while (b > 0)
//     {
//         if (b & 1)
//         {
//             res = (res * a) % MOD;
//         }
//         a = (a * a) % MOD;
//         b = (b >> 1);
//     }
//     return res;
// }
struct SegmentTree
{
    vl tree;
    SegmentTree(int n, vl &arr)
    {
        tree.resize(4 * n);
        BuildTree(arr, 0, 0, n - 1);
    }
    void BuildTree(vl &arr, int node, int l, int r)
    {
        if (l == r)
        {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        BuildTree(arr, node * 2 + 1, l, mid);
        BuildTree(arr, node * 2 + 2, mid + 1, r);
        tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }
    void update(int node, int indx, ll val, ll prev, int l, int r)
    {
        if (indx < l || r < indx)
            return;
        if (l == r)
        {
            tree[node] -= prev;
            tree[node] += val;
            return;
        }
        int mid = (l + r) / 2;
        if (indx <= mid)
        {
            update(node * 2 + 1, indx, val, prev, l, mid);
        }
        else
        {
            update(node * 2 + 2, indx, val, prev, mid + 1, r);
        }
        tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }
    ll query(int node, int ql, int qr, int l, int r)
    {
        if (qr < l || r < ql)
            return 0;
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        return query(node * 2 + 1, ql, qr, l, mid) + query(node * 2 + 2, ql, qr, mid + 1, r);
    }
};
vi in, out;
vl vals;
vvi grid;
void inout(int node, int par, int &time)
{
    in[node] = time++;
    for (int nn : grid[node])
    {
        if (nn == par)
            continue;
        inout(nn, node, time);
    }
    out[node] = time;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, time = 0;
    cin >> n >> m;
    in.resize(n + 1);
    out.resize(n + 1);
    vals.resize(n + 1);
    grid.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> vals[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }
    inout(1, -1, time);
    vl arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        arr[in[i]] += vals[i];
        arr[out[i]] -= vals[i];
    }
    SegmentTree obj(n, arr);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b;
        if (a == 1)
        {
            cin >> c;
            obj.update(0, in[b], c, vals[b], 0, n - 1);
            obj.update(0, out[b], -c, -vals[b], 0, n - 1);
            vals[b] = c;
        }
        else
        {
            cout << obj.query(0, 0, in[b], 0, n - 1) << endl;
        }
    }
    return 0;
}