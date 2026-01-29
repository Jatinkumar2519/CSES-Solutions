#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1e9 + 7;

struct Matrix {
    ll a, b, c, d;
};

Matrix multiply(Matrix x, Matrix y) {
    return {
        (x.a * y.a + x.b * y.c) % MOD,
        (x.a * y.b + x.b * y.d) % MOD,
        (x.c * y.a + x.d * y.c) % MOD,
        (x.c * y.b + x.d * y.d) % MOD
    };
}

Matrix power(Matrix base, ll n) {
    Matrix res = {1, 0, 0, 1}; // Identity matrix
    while (n > 0) {
        if (n & 1) res = multiply(res, base);
        base = multiply(base, base);
        n >>= 1;
    }
    return res;
}

ll fib(ll n) {
    if (n == 0) return 0;
    Matrix F = {1, 1, 1, 0};
    Matrix Fn = power(F, n - 1);
    return Fn.a % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<ll> tree(4 * n);

    function<void(int, int, int)> buildTree = [&](int node, int l, int r) {
        if (l == r) {
            tree[node] = fib(arr[l]);
            return;
        }
        int mid = (l + r) / 2;
        buildTree(node * 2 + 1, l, mid);
        buildTree(node * 2 + 2, mid + 1, r);
        tree[node] = __gcd(tree[node * 2 + 1], tree[node * 2 + 2]);
    };
    buildTree(0, 0, n - 1);

    function<ll(int, int, int, int, int)> query = [&](int node, int ql, int qr, int l, int r) -> ll {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        ll left = query(node * 2 + 1, ql, qr, l, mid);
        ll right = query(node * 2 + 2, ql, qr, mid + 1, r);
        return __gcd(left, right);
    };

    while (m--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << (query(0, l, r, 0, n - 1) % MOD) << "\n";
    }

    return 0;
}
