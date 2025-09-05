#include <bits/stdc++.h>
using namespace std;

long long solve(long long n){
    int mod = 1e9 + 7;
    vector<long long> dp(n + 1,0);
    dp[0] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= 6;j++){
            if(i - j >= 0)
                dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }
    return dp[n];
}
int main() {
    long long n;
    cin >> n;
    cout<< solve(n);
    return 0;
}