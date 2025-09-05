#include <bits/stdc++.h>
using namespace std;

int solve(long long a, long long x, int mod) {
    long long res = 1;
    a %= mod;
    while (x > 0) {
        if (x & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        x >>= 1;
    }
    return res;
}

int main() {
    int mod = 1e9 + 7;
    int n;
    cin >> n;
    for (int _ = 0; _ < n; _++) {
        long long i, j, k;
        cin >> i >> j >> k;
        int num = solve(j, k, mod - 1);
        cout << solve(i, num, mod) << endl;
    }
    return 0;
}
