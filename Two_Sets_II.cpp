#include <bits/stdc++.h>
using namespace std;

int solve(long long n, long long target) {
    vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, 0));
    dp[0][0] = 1;
    int mod = 1e9 + 7;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= target;j++){
            dp[i][j] = dp[i - 1][j];
            if(j - i >= 0){
                dp[i][j] = (dp[i][j] + dp[i - 1][j - i]) % mod;
            }
        }
    }
    return dp[n][target];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long long n;
    cin >> n;
    long long total = n * (n + 1) / 2;
    if (total % 2 != 0) {
        cout << 0 << '\n';
    } else {
        cout << solve(n, total / 2) << '\n';
    }
    return 0;
}
