#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> arr(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }

    vector<pair<int, int>> tree(4 * n);
    auto merge = [&](pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first >= b.first)
            return a;
        return b;
    };
    function<void(int, int, int)> init = [&](int node, int l, int r) -> void
    {
        if (l > r)
            return;
        if (l == r)
        {
            tree[node] = {nums[l], l};
            return;
        }
        int mid = (l + r) / 2;
        init(node * 2 + 1, l, mid);
        init(node * 2 + 2, mid + 1, r);
        tree[node] = merge(tree[node * 2 + 1], tree[node * 2 + 2]);
    };
    function<void(int, int, int, int, int)> update = [&](int node, int l, int r, int val, int indx) -> void
    {
        if (indx < l || r < indx)
            return;
        if (l == r)
        {
            tree[node] = {val, l};
            return;
        }
        int mid = (l + r) / 2;
        update(node * 2 + 1, l, mid, val, indx);
        update(node * 2 + 2, mid + 1, r, val, indx);
        tree[node] = merge(tree[node * 2 + 1], tree[node * 2 + 2]);
    };
    function<pair<int, int>(int, int, int, int, int)> query = [&](int node, int ql, int qr, int l, int r) -> pair<int, int>
    {
        if (qr < l || r < ql)
            return {-1, -1};
        if (ql <= l && r <= qr)
        {
            return tree[node];
        }
        int mid = (l + r) / 2;
        pair<int, int> left = query(node * 2 + 1, ql, qr, l, mid);
        pair<int, int> right = query(node * 2 + 2, ql, qr, mid + 1, r);
        if (left == make_pair(-1, -1))
            return right;
        if (right == make_pair(-1, -1))
            return left;
        return merge(left, right);
    };
    function<int(int, int, int, int)> findFirst = [&](int node, int l, int r, int target) -> int
    {
        if (tree[node].first < target)
            return -1;
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        if (tree[node * 2 + 1].first >= target)
            return findFirst(node * 2 + 1, l, mid, target);
        return findFirst(node * 2 + 2, mid + 1, r, target);
    };

    init(0, 0, n - 1);

    for (int i = 0; i < m; i++)
    {
        int idx = findFirst(0, 0, n - 1, arr[i]);
        if (idx == -1)
        {
            cout << 0 << " ";
        }
        else
        {
            cout << idx + 1 << " ";
            nums[idx] -= arr[i];
            update(0, 0, n - 1, nums[idx], idx);
        }
    }
    return 0;
}