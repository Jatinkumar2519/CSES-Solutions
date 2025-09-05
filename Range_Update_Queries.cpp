#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct SegTree {
    int n;
    vector<ll> lazy;

    SegTree(int n) : n(n) {
        lazy.assign(4*n, 0);
    }

    // Range update: add val to [ql, qr]
    void update(int idx, int l, int r, int ql, int qr, ll val) {
        if (qr < l || r < ql) return;  // no overlap
        if (ql <= l && r <= qr) {      // fully inside
            lazy[idx] += val;
            return;
        }
        int mid = (l + r) / 2;
        update(idx*2+1, l, mid, ql, qr, val);
        update(idx*2+2, mid+1, r, ql, qr, val);
    }

    // Point query: get value at position pos
    ll query(int idx, int l, int r, int pos) {
        if (l == r) {
            return lazy[idx];
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
            return lazy[idx] + query(idx*2+1, l, mid, pos);
        else
            return lazy[idx] + query(idx*2+2, mid+1, r, pos);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    SegTree st(n);

    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            ll v;
            cin >> l >> r >> v;
            st.update(0, 0, n-1, l-1, r-1, v);  // add v to [l-1, r-1]
        } else {
            int idx;
            cin >> idx;
            ll extra = st.query(0, 0, n-1, idx-1);
            cout << nums[idx-1] + extra << "\n";
        }
    }

    return 0;
}
