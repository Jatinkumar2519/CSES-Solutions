#include <bits/stdc++.h>
# define ll long long
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,w;
    cin >> n >> w;
    vector<int> wt(n);
    vector<ll> val(n);
    for(int i =0;i < n;i++){
        cin >> wt[i] >> val[i];
    }
    vector<vector<ll>> dp(n + 1,vector<ll>(w + 1,0));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= w;j++){
            if(j - wt[i - 1] >= 0){
                dp[i][j] = max(dp[i - 1][j],val[i - 1] + dp[i - 1][j - wt[i - 1]]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout<< dp[n][w];
    return 0;
}