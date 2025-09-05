#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n,m) resize(n,m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;
const int MOD = 1e9 + 7;
// long long powmod(long long a,long long b){
//     long long res = 1;
//     while(b > 0){
//         if(b & 1){
//            res = (res * a) % MOD;
//         }
//         a = (a * a) % MOD;
//         b = (b >> 1);
//     }
//     return res;
// }
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vvi grid(n + 1);
    for(int i = 0;i < m;i++){
        int a,b;
        cin >> a >> b;
        grid[a].push_back(b);
    }
    vector<int> parent(n + 1,-1);
    priority_queue<pair<int,int>> pq;
    pq.push({0,1});
    vector<int> dp(n + 1, 0);
    while(!pq.empty()){
        auto temp = pq.top();pq.pop();
        int len = temp.first;
        int node = temp.second;
        if(dp[node] > len) continue;
        for(int nn : grid[node]){
            if(dp[nn] < len + 1){
                dp[nn] = len + 1;
                parent[nn] = node;
                pq.push({len + 1,nn});
            }
        }
    }
    vector<int> path;
    int u = n;
    while(u != -1){
        path.push_back(u);
        u = parent[u];
    }
    reverse(path.begin(),path.end());
    if(path[0] != 1) {
        cout<< "IMPOSSIBLE" ;
        return 0;
    }
    cout<< path.size() << endl;
    for(int i : path){
        cout<< i << ' ';
    }
    return 0;
}