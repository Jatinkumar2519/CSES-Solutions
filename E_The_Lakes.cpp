#include <bits/stdc++.h>
using namespace std;
vector<int> dirx = {-1,1,0,0};
vector<int> diry = {0,0,-1,1};
int calc(vector<vector<int>>& grid,int i,int j,int m,int n,vector<vector<int>>& visit){
    queue<pair<int,int>> q;
    q.push({i,j});
    int sum = 0;
    while(!q.empty()){
        auto pair = q.front();q.pop();
        int x = pair.first;
        int y = pair.second;
        sum += grid[x][y];
        for(int d = 0;d < 4;d++){
            int ni = x + dirx[d];
            int nj = y + diry[d];
            if(ni >= 0 && nj >= 0 && ni < m && nj < n && visit[ni][nj] == 0 && grid[ni][nj] > 0){
                visit[ni][nj] = 1;
                q.push({ni,nj});
            }
        }
    }
    return sum;
}
int solve(){
    int m,n;
    cin >> m >>n;
    vector<vector<int>> grid(m,vector<int>(n,0));
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            cin >> grid[i][j];
        }
    }
    int maxval = 0;
    vector<vector<int>> visit(m,vector<int>(n,0));
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            if(visit[i][j] || grid[i][j] == 0) continue;
            visit[i][j] = 1;
            maxval = max(maxval,calc(grid,i,j,m,n,visit));
        }
    }
    return maxval;
}
int main() {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cout<< solve() << endl;
    }
    return 0;
}