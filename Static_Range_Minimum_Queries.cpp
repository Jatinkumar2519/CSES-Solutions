#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    int l = log2(n) + 1;
    vector<vector<int>> dp(n,vector<int>(l));
    for(int i = 0;i < n;i++){
        dp[i][0] = arr[i];
    }
    for(int j = 1;(1 << j) <= n;j++){
        for(int i = 0;(i + (1 << j) - 1) < n;i++){
            dp[i][j] = min(dp[i][j - 1],dp[i + (1 << (j - 1))][j - 1]);
        }
    }
    for(int i = 0;i < m;i++){
        int l,r;
        cin >> l >> r;
        l--,r--;
        int len = log2(r - l + 1);
        cout<< min(dp[l][len],dp[r - (1 << len) + 1][len]) << endl;
    }
    return 0;
}