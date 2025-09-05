#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n,m) resize(n,m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;
const int MOD = 1e9 + 7;
int n,m;
int dp[11][1001];
int solve(vector<vector<bool>>& matrix,int i,int j){
    if(i == n - 1 && j == m - 1) return 1;
    if(i + 1 < n && !matrix[i + 1][j]){
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    memset(dp,-1,sizeof(dp));
    cin >> n >> m;
    vector<vector<bool>> matrix(n,vector<bool>(m));
    cout<<  solve(matrix,0,0);
    return 0;
}