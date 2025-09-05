#include <bits/stdc++.h>
#define ll long long
using namespace std;

string solve() {
    int n;
    cin >> n;
    vector<ll> pre(n), suf(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> suf[i];
    }

    for (int i = 0; i < n; i++) {
        ll p = (i == 0) ? 0 : pre[i - 1];
        ll s = (i == n - 1) ? 0 : suf[i + 1];
        ll lcm_val = pre[i] / __gcd(pre[i], suf[i]) * suf[i]; // to avoid overflow
        if (__gcd(lcm_val, p) != pre[i] || __gcd(lcm_val, s) != suf[i]) {
            return "NO";
        }
    }

    return "YES";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t; // t = number of test cases
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}
