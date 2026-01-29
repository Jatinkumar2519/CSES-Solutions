#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;

    vector<int> next(n + 1);
    for(int i = 1;i <= n;i++){
        cin >> next[i];
    }

    vector<int> vis(n + 1,0);
    vector<int> result(n + 1);

    for(int node = 1;node <= n;node++){
        if(vis[node]) continue;
        
        int curr = node;
        while(!vis[curr]){
            vis[curr] = node;
            curr = next[curr];
        }

        if(vis[curr] == node){

            int len = 1;
            for(int i = next[curr];i != curr;i = next[i]){
                len++;
            }

            int i = curr;
            do {
                vis[i] = -1;
                result[i] = len;
                i = next[i];
            } while (i != curr);

        }
    }

    function<int(int)> solve = [&](int node)->int{
        if(result[node]) return result[node];
        return result[node] = solve(next[node]) + 1;
    };

    for(int i = 1;i <= n;i++){
        if(result[i] == 0){
            solve(i);
        }
    }

    for(int i = 1;i <= n;i++){
        cout<< result[i] << ' ';
    }
    return 0;
}
