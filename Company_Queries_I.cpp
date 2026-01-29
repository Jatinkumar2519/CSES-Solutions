#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> parent(n + 1,-1);

    for(int i = 2;i <= n;i++){
        cin >> parent[i];
    }

    int len = 32;
    vector<vector<int>> table(n + 1,vector<int>(len,-1));

    for(int i = 1;i <= n;i++){
        table[i][0] = parent[i];
    }

    for(int j = 1;j < len;j++){
        for(int i = n;i > 0;i--){
            if(table[i][j - 1] != -1)
                table[i][j] = table[table[i][j - 1]][j - 1];
        }
    }
    
    for(int i = 0;i < m;i++){
        int x,k;
        cin >> x >> k;
        
        int node = x;

        for(int j = 31;j >= 0;j--){
            if(k & (1 << j)){
                node = table[node][j];
                if(node == -1){
                    break;
                }
            }
        }
        cout<< node << endl;
    }
    return 0;
}