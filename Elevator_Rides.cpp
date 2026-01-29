#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long capacity;
    cin >> n >> capacity;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int dp[(1 << 20)];
    function<int(int)> solve = [&](int mask){
        if(__builtin_popcount(mask) == n) return 0;

        if(dp[mask] != -1) return dp[mask];

        int minv = INT_MAX;
        
        for(int i = 0;i < (1 << n);i++){
            long long sum = 0;
            int newmask = mask;
            for(int b = 0;b < n;b++){
                if((mask & (1 << b)) > 0 || (i & (1 << b)) == 0) continue;
                newmask |= (1 << b);
                sum += arr[b];
            }
            minv = min(minv,1 + solve(newmask));
        }
        return dp[mask] = minv;
    };

    memset(dp,-1,sizeof(dp));
    cout<< solve(0);
    return 0;
}
