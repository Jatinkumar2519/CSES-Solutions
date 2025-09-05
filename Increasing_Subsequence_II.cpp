#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

struct SegmentTree {
    vector<long long> tree;
    int size;

    SegmentTree(int n) {
        size = n;
        tree.resize(4 * n, 0);
    }

    void update(int node, int l, int r, int idx, long long val) {
        if (l == r) {
            tree[node] = (tree[node] + val) % mod;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2 * node + 1, l, mid, idx, val);
        else update(2 * node + 2, mid + 1, r, idx, val);
        tree[node] = (tree[2 * node + 1] + tree[2 * node + 2]) % mod;
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return (query(2 * node + 1, l, mid, ql, qr) +
                query(2 * node + 2, mid + 1, r, ql, qr)) % mod;
    }

    void update(int idx, long long val) {
        update(0, 0, size - 1, idx, val);
    }

    long long query(int l, int r) {
        if (l > r) return 0;
        return query(0, 0, size - 1, l, r);
    }
};

long long countIncreasingSubsequences(vector<int>& arr) {
    int n = arr.size();
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    unordered_map<int, int> compress;
    for (int i = 0; i < sorted.size(); ++i)
        compress[sorted[i]] = i;

    SegmentTree st(sorted.size());

    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        int idx = compress[arr[i]];
        long long total = 1;
        if (idx > 0)
            total = (total + st.query(0, idx - 1)) % mod;
        cout<< total << endl;
        st.update(idx, total);
        ans = (ans + total) % mod;
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << countIncreasingSubsequences(arr) << '\n';
    return 0;
}
