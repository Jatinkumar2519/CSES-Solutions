#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> grid;
vector<int> color;
vector<int> result;

unordered_set<int>* solve(int node, int par) {
    unordered_set<int>* bigset = new unordered_set<int>();
    for(int nn : grid[node]){
        if(nn == par) continue;
        unordered_set<int>* childset = solve(nn,node);
        if(bigset->empty() || childset->size() > bigset->size()){
            auto temp = childset;
            childset = bigset;
            bigset = temp;
        }
        for(int num : *childset){
            bigset->insert(num);
        }
    }
    bigset->insert(color[node]);
    result[node] = bigset->size();
    return bigset;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    color.resize(n + 1);
    result.resize(n + 1);
    grid.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }

    solve(1, -1);
    
    for (int i = 1; i <= n; i++) {
        cout << result[i] << ' ';
    }
    return 0;
}
