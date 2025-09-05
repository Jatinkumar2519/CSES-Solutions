#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n,m) resize(n,m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;
const int MOD = 1e9 + 7;
long long powmod(long long a,long long b){
    long long res = 1;
    while(b > 0){
        if(b & 1){
           res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b = (b >> 1);
    }
    return res;
}
int n,m;
vector<int> dirx = {-1,1,0,0};
vector<int> diry = {-0,0,-1,1};
vector<vector<char>> grid;
void solve(int i,int j){
    if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '#'){
        return;
    }
    grid[i][j] = '#';
    for(int d = 0;d < 4;d++){
        solve(i + dirx[d],j + diry[d]);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    grid.resize(n,vector<char>(m));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> grid[i][j];
        }
    }
    int count = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(grid[i][j] == '.'){
                count++;
                solve(i,j);
            }
        }
    }
    cout<< count;
    return 0;
}