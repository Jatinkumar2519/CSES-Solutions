#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    
    vector<vector<char>> grid(n,vector<char>(n));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(n + 1,vector<int>(n + 1,0));

    for(int i = 1;i <= n;i++){
        dp[i][1] = (grid[i - 1][0] == '*');
        for(int j = 2;j <= n;j++){
            dp[i][j] += dp[i][j - 1] + (grid[i - 1][j - 1] == '*');
        }
    }

    for(int j = 1;j <= n;j++){
        for(int i = 2;i <= n;i++){
            dp[i][j] += dp[i - 1][j];
        }
    }

    for(int i = 0;i < m;i++){
        int p,q,r,s;
        cin >> p >> q >> r >> s;

        cout<< dp[r][s] - dp[r][q - 1] - dp[p - 1][s] + dp[p - 1][q - 1] << endl;
    }
    return 0;
}