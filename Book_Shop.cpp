#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,cp;
    cin >> n >> cp;
    vector<int> wt(n),val(n);
    for(int i = 0;i < n;i++){
        cin >> wt[i];
    }
    for(int i = 0;i < n;i++){
        cin >> val[i];
    }
    vector<vector<int>> dp(n + 1,vector<int>(cp + 1,0));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= cp;j++){
            dp[i][j] = dp[i - 1][j];
            if(j - wt[i - 1] >= 0){
                dp[i][j] = max(dp[i][j],val[i - 1] + dp[i - 1][j - wt[i - 1]]);
            }
        }
    }
    cout<< dp[n][cp];
    return 0;
}