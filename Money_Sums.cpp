#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr,int n,long long target){
    vector<vector<int>> dp(n + 1,vector<int>(target + 1,0));
    for(int i = 0;i <= n;i++){
        dp[i][0] = 1;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= target;j++){
            if(j - arr[i - 1] >= 0)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    vector<int> res;
    for(int i = 1;i <= target;i++){
        if(dp[n][i]) res.push_back(i);
    }
    cout<< res.size() << endl;
    for(int i : res){
        cout<< i << ' ';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    long long target = accumulate(arr.begin(),arr.end(),1LL);
    solve(arr,n,target);
    return 0;
}