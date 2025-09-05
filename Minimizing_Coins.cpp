#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr,int target){
    vector<int> dp(target + 1,INT_MAX);
    dp[0] = 0;
    for(int i = 1;i <= target;i++){
        for(int& num : arr){
            if(i - num >= 0 && dp[i - num] != INT_MAX){
                dp[i] = min(dp[i],1 + dp[i - num]);
            }
        }
    }
    return (dp[target] == INT_MAX) ? -1 : dp[target];
}
int main() {
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    cout<< solve(arr,k);
    return 0;
}