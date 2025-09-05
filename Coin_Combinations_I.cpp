#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& arr,int target){
    vector<long long> dp(target + 1,0);
    dp[0] = 1;
    int mod = 1e9 + 7;
    for(int i = 1;i <= target;i++){
        for(auto& num : arr){
            if(i - num >= 0){
                dp[i] = (dp[i] + dp[i - num]) % mod;
            }
        }
    }
    return dp[target];
}
int main() {
    int n,k;
    cin >> n >> k;
    vector<long long> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    cout<< solve(arr,k);
    return 0;
}