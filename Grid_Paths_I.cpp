#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long solve(vector<vector<char>>& grid,int n){
    if(grid[0][0] == '*' || grid[n - 1][n - 1] == '*') return 0;
    vector<vector<long long>> dp(n + 1,vector<long long>(n + 1,0));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i == 1 && j == 1){
                dp[i][j] = 1LL;
                continue;
            }
            if(grid[i - 1][j - 1] == '*'){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            }
        }
    }
    return dp[n][n];
}
int main() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n,vector<char>(n));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> grid[i][j];
        }
    }
    cout<< solve(grid,n);
    return 0;
}