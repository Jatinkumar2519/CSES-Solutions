#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1e9 + 7;

vector<vector<ll>> mul(const vector<vector<ll>>& a, const vector<vector<ll>>& b) {
    vector<vector<ll>> res(3, vector<ll>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return res;
}

vector<vector<ll>> power(vector<vector<ll>> base, long long exp) {
    vector<vector<ll>> result = {{1,0,0}, {0,1,0}, {0,0,1}}; 
    while (exp > 0) {
        if (exp & 1) result = mul(result, base);
        base = mul(base, base);
        exp >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }
        if (n == 2 || n == 3) {
            cout << 1 << '\n';
            continue;
        }

        vector<vector<ll>> M = {
            {1, 1, 1},
            {1, 0, 0},
            {0, 1, 0}
        };

        vector<vector<ll>> R = power(M, n - 3);

        ll ans = (R[0][0] + R[0][1]) % MOD;
        cout << ans << '\n';
    }

    return 0;
}
