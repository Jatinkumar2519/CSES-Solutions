#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;

    int dp[n][2];
    function<int(int,int)> solve = [&](int curr,int prev){
        if(curr == n) return 1;

        if(dp[curr][prev] != -1) return dp[curr][prev];

        if(prev == 0){
            return dp[curr][prev] = solve(curr + 1,1);
        }
        else{
            return dp[curr][prev] = solve(curr + 1,1) + solve(curr + 1,0);
        }
    };

    memset(dp,-1,sizeof(dp));
    cout<< solve(0,1);
    return 0;
}