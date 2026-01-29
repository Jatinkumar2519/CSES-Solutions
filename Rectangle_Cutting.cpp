#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    if(n > m) swap(n,m);
    vector<vector<int>> dp(n + 1,vector<int>(m + 1,-1));
    function<int(int,int)> solve = [&](int a,int b)->int{
        if(a == b) return 0;
        if(a > b) swap(a,b);
        if(dp[a][b] != -1) return dp[a][b];
        int res = INT_MAX;
        for(int i = 1;i + 1 <= a;i++){
            res = min(res,1 + solve(i,b) + solve(a - i,b));
        }
        for(int i = 1;i + 1 <= b;i++){
            res = min(res,1 + solve(a,i) + solve(a,b - i));
        }
        return dp[a][b] = res;
    };
    cout<< solve(n,m);
    return 0;
}