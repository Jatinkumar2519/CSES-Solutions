#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    const int MAXSUM = 1e6 + 1;
    static ll dp[MAXSUM] = {0};
    dp[0] = 1;

    for (int x : arr) {
        for (int j = MAXSUM - 1; j >= x; j--) {
            dp[j] = (dp[j] + dp[j - x]) % MOD;
        }
    }

    static ll prefix[MAXSUM] = {0};
    prefix[0] = dp[0];
    for (int i = 1; i < MAXSUM; i++)
        prefix[i] = (prefix[i - 1] + dp[i]) % MOD;

    while (m--) {
        int l, r;
        cin >> l >> r;
        ll ans = (prefix[r] - (l ? prefix[l - 1] : 0) + MOD) % MOD;
        cout << ans << "\n";
    }

    return 0;
}
