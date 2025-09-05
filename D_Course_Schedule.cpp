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
    vvi grid;
    grid.resize(n + 1);
    vector<int> degree(n + 1);
    for(int i = 0;i < m;i++){
        int a,b;
        cin >> a >> b;
        degree[a]++;
        grid[b].push_back(a);
    }
    queue<int> q;
    for(int i = 1;i <= n;i++){
        if(degree[i] == 0){
            q.push(i);
        }
    }
    vector<int> res;
    while(!q.empty()){
        int node = q.front();q.pop();
        res.push_back(node);
        for(int nn : grid[node]){
            if(--degree[nn] == 0){
                q.push(nn);
            }
        }
    }
    if(res.size() != n){
        cout<< "IMPOSSIBLE" ;
        return 0;
    }
    reverse(res.begin(),res.end());
    for(int i : res){
        cout<< i << ' ';
    }
    return 0;
}