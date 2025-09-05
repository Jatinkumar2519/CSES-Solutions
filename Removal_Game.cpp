#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n,m) resize(n,m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;
const int MOD = 1e9 + 7;
map<int,map<int,map<int,ll>>> dp;
ll solve(vector<ll>& arr,int i,int j,int turn){
    if(i == j) {
        return (turn == 0)? arr[i] : 0; 
    }
    if(dp.count(i) && dp[i].count(j) && dp[i][j].count(turn)) return dp[i][j][turn];
    if(turn == 0){
        return dp[i][j][turn] = max(arr[i] + solve(arr,i + 1,j,1 - turn),arr[j] + solve(arr,i,j - 1,1 - turn));
    }
    else{
        return dp[i][j][turn] = min(solve(arr,i + 1,j,1 - turn),solve(arr,i,j - 1,1 - turn));
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<ll> arr(n);
    dp.clear();
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    cout<< solve(arr,0,n - 1,0);
    return 0;
}