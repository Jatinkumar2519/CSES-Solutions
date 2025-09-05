#include <bits/stdc++.h>
using namespace std;
int dp[5001][5001];
int solve(string& s1,string& s2,int i,int j){
    int n = s1.length();
    int m = s2.length();
    if(i == n) return m - j;
    if(j == m) return n - i;
    if(dp[i][j] != -1) return dp[i][j];
    if(s1[i] == s2[j]){
        return dp[i][j] = solve(s1,s2,i + 1,j + 1);
    }
    return dp[i][j] = 1 + min({solve(s1,s2,i + 1,j),solve(s1,s2,i + 1,j + 1),solve(s1,s2,i,j + 1)});
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s1,s2;
    cin >> s1>> s2;
    memset(dp,-1,sizeof(dp));
    cout<< solve(s1,s2,0,0);
    return 0;
}