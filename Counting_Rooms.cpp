#include <bits/stdc++.h>
using namespace std;
vector<int> dirx = {-1,1,0,0};
vector<int> diry = {0,0,-1,1};
void solve(vector<vector<char>>& grid,int i,int j){
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '#') return;
    grid[i][j] = '#';
    for(int d = 0;d < 4;d++){
        solve(grid,i + dirx[d],j + diry[d]);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> grid[i][j];
        }
    }
    int count = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(grid[i][j] == '.'){
                solve(grid,i,j);
                count++;
            }
        }
    }
    cout<< count;
    return 0;
}