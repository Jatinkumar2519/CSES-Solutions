#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<char>> mat(n,vector<char>(m));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> mat[i][j];
        }
    }
    int dirx[4] = {-1,1,0,0};
    int diry[4] = {0,0,-1,1};
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(mat[i][j] == '#'){
                int count = 0;
                for(int d = 0;d < 4;d++){
                    int ni = i + dirx[d];
                    int nj = j + diry[d];
                    if(ni >= 0 && nj >= 0 && ni < n && nj < m && mat[ni][nj] == '#') count++;
                }
                if(count != 2 && count != 4){
                    cout<< "No";
                    return 0;
                }
            }
        }
    }
    cout<< "Yes";
    return 0;
}