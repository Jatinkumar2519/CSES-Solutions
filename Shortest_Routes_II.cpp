#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m,l;
    cin >> n >> m >> l;
    vector<vector<long long>> grid(n + 1,vector<long long>(n + 1,LLONG_MAX));
    for(int i = 0;i < m;i++){
        int a,b;
        long long c;
        cin >> a >> b >> c;
        grid[a][b] = min(grid[a][b],c);
        grid[b][a] = min(grid[a][b],c);
    }
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(i == j){
                    grid[i][j] = 0;
                    continue;
                }
                if(grid[i][k] != LLONG_MAX && grid[k][j] != LLONG_MAX)
                    grid[i][j] = min(grid[i][j],grid[i][k] + grid[k][j]);
            }
        }
    }
    for(int i = 0;i < l;i++){
        int a,b;
        cin >> a >> b;
        if(grid[a][b] == LLONG_MAX){
            cout<< -1 << endl;
        }
        else
            cout<< grid[a][b] << endl;
    }
    return 0;
}