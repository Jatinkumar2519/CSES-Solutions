#include <bits/stdc++.h>
using namespace std;
int dp[100001][102];
const int mod = 1e9 + 7;
int solve(vector<int>& arr,int i,int prev,int k,int n){
    if(i == n) return 1;
    if(dp[i][prev] != -1) return dp[i][prev];
    if(arr[i] != 0){
        if(prev != 0 && abs(prev - arr[i]) > 1) return 0;
        return dp[i][prev] = solve(arr,i + 1,arr[i],k,n) % mod;
    }
    else if(prev == 0){
        int sum = 0;
        for(int num = 1;num <= k;num++){
            sum = (sum + solve(arr,i + 1,num,k,n)) % mod;
        }
        return dp[i][prev] = sum;
    }
    else{
        int sum = 0;
        for(int num = max(1,prev - 1);num <= min(k,prev + 1);num++){
            sum = (sum + solve(arr,i + 1,num,k,n)) % mod;
        }
        return dp[i][prev] = sum;
    }
}
int main() {
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    memset(dp,-1,sizeof(dp));
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    cout<< solve(arr,0,0,k,n);
    return 0;
}