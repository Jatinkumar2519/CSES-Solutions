#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<vector<char>> grid(n,vector<char>(n));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> grid[i][j];
        }
    }
    
    string res = string(1,grid[0][0]);
    unordered_set<ll> next,cur;
    cur.insert(0);

    for(int i = 0;i < 2*n - 2;i++){
        next.clear();

        char best = 'Z';

        for(auto& indx : cur){
            int x = (int) indx / 3000;
            int y = (int) indx % 3000;

            if(x + 1 < n){
                best = min(best,grid[x + 1][y]);
            }
            if(y + 1 < n){
                best = min(best,grid[x][y + 1]);
            }
        }

        for(auto& indx : cur){
            int x = (int) indx / 3000;
            int y = (int) indx % 3000;

            if(x + 1 < n && best == grid[x + 1][y]){
                next.insert((x + 1) * 3000 * 1LL + y);
            }
            if(y + 1 < n && best == grid[x][y + 1]){
                next.insert(x * 3000 * 1LL + (y + 1));
            }
        }

        cur = next;
        res.push_back(best);
    }

    cout<< res;
    return 0;
}