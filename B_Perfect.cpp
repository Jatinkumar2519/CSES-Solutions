#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> arr(n + 1);
    for(int i = 1;i <= n;i++){
        arr[i] = {INT_MAX,0,i};
    }
    int rankk = 1;
    for(int i = 0;i < k;i++){
        int u,v;
        cin >> u >> v;
        if(++arr[u][1] == m){
            arr[u][0] = rankk++;
        }
    }
    sort(arr.begin(),arr.end());
    for(int i = 1;i <= n;i++){
        if(arr[i][1] == m) cout<< arr[i][2] << ' ';
    }
    return 0;
}