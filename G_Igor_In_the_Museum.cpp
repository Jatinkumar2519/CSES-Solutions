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
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> grid[i][j];
        }
    }
    int dirx[] = {-1,1,0,0};
    int diry[] = {0,0,-1,1};
    vector<vector<int>> visit(n,vector<int>(m,-1));
    for(int _ = 0;_ < k;_++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        int count = 0;
        for(int x = 0;x < n;x++){
            for(int y = 0;y < m;y++){
                if(grid[x][y] == '.' && visit[x][y] == -1){
                    for(int d = 0;d < 4;d++){
                        int nx = x + dirx[d];
                        int ny = y + diry[d];
                        if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                            if(grid[nx][ny] == '*') count++;
                        }
                    }
                }
            }
        }
        cout<< count << endl;
    }
    return 0;
}