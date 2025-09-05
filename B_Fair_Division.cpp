#include <bits/stdc++.h>
using namespace std;

string solve(){
    int n;
    cin >> n;
    int sum = 0;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        int num;
        cin >> num;
        arr[i] = num;
        sum += num;
    }
    if(sum % 2 != 0) return "NO";
    int target = sum / 2;
    vector<vector<bool>> dp(n + 1,vector<bool>(target + 1));
    for(int i = 0;i <= n;i++){
        dp[i][0] = true;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= target;j++){
            if(j >= arr[i - 1]){
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    }
    return (dp[n][target]) ? "YES" : "NO";
}
int main() {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cout<< solve() << endl;
    }
    return 0;
}   