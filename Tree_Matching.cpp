#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid;
vector<vector<int>> dp;
vector<bool> visit;
int solve(int node,int par,bool turn){
    
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    grid.resize(n + 1);
    dp.resize(n + 1,vector<int>(2,-1));
    for(int i = 0;i < n - 1;i++){
        int a,b;
        cin >> a >> b;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }
    cout<< solve(1,-1,true);
    return 0;
}