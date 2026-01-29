#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9 + 7;

int n,m;
vector<vector<int>> dp;
vector<vector<int>> grid;

void init_dp(){
    for(int i = 0;i < n;i++){
        dp[i][0] = grid[i][0];
        for(int j = 1;j < m;j++){
            dp[i][j] = dp[i][j - 1] + grid[i][j];
        }
    }
    
    for(int j = 0;j < m;j++){
        for(int i = 1;i < n;i++){
            dp[i][j] += dp[i - 1][j];
        }
    }
}

int getSum(int x1,int y1,int x2,int y2){
    int sum = dp[x2][y2];
    if(x1 > 0){
        sum -= dp[x1 - 1][y2];
    }
    if(y1 > 0){
        sum -= dp[x2][y1 - 1];
    }
    if(x1 > 0 && y1 > 0){
        sum += dp[x1 - 1][y1 - 1];
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int k;
    cin >> n >> m >> k;
    dp.resize(n,vector<int>(m));
    grid.resize(n,vector<int>(m));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> grid[i][j];
        }
    }
    init_dp();
    int q;
    cin >> q;
    while(q--){
        int i,j;
        cin >> i >> j;

        int len = min({i,j,n - i - 1,m - j - 1});
        
        int left = 0;
        int right = len;
        while(left < right){
            int mid = (left + right + 1)/2;
            int sum = getSum(i - mid,j - mid,i + mid,j + mid);
            if(sum > k){
                right = mid - 1;
            }
            else{
                left = mid;
            }
        }
        cout<< left * 2 + 1 << endl;
    }
    return 0;
}
