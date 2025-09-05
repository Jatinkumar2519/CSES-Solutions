#include <bits/stdc++.h>
using namespace std;
int dp[5001][5001];
int solve(string& a,string& b,int i,int j){
    if(i == a.length()) return b.length() - j;
    if(j == b.length()) return a.length() - i;
    if(dp[i][j] != -1) return dp[i][j];
    if(a[i] == b[j]){
        return dp[i][j] = solve(a,b,i + 1,j + 1);
    }
    return dp[i][j] = 1 + min({solve(a,b,i + 1,j),solve(a,b,i + 1,j + 1),solve(a,b,i,j + 1)});
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    memset(dp,-1,sizeof(dp));
    string a,b;
    cin >> a >> b;
    cout<< solve(a,b,0,0);
    return 0;
}