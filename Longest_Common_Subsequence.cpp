#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int solve(vector<long long>& arr1,vector<long long>& arr2,int i,int j){
    if(i == arr1.size() || j == arr2.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(arr1[i] == arr2[j]){
        return dp[i][j] = 1 + solve(arr1,arr2,i + 1,j + 1);
    }
    return dp[i][j] = max(solve(arr1,arr2,i + 1,j),solve(arr1,arr2,i,j + 1));
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    dp.resize(n + 1,vector<int>(m + 1,-1));
    vector<long long> arr1(n),arr2(m);
    for(int i = 0;i < n;i++){
        cin >> arr1[i];
    }
    for(int i = 0;i < m;i++){
        cin >> arr2[i];
    }
    cout<< solve(arr1,arr2,0,0) << endl;
    int i = 0,j = 0;
    while(i < n && j < m){
        if(arr1[i] == arr2[j]){
            cout<< arr1[i] << " ";
            i++;j++;
        }
        else if(dp[i + 1][j] >= dp[i][j + 1]){
            i++;
        }
        else{
            j++;
        }
    }
    return 0;
}