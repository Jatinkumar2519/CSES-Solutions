# include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> visit;
    vector<int> color;
    bool solve(vector<vector<int>>& graph,int node,int par,int col){
        visit[node] = true;
        color[node] = col;
        for(int nn : graph[node]){
            if(par == nn) continue;
            if(visit[nn]){
                if(color[nn] == col) return false;
            }
            else{
                if(col == 1){
                    if(!solve(graph,nn,node,2)) return false;
                }
                else{
                    if(!solve(graph,nn,node,1)) return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        visit.resize(n + 1,false);
        color.resize(n + 1,0);
        vector<vector<int>> graph(n + 1);
        for(auto& edge : dislikes){
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i = 1;i <= n;i++){
            if(visit[i]) continue;
            if(!solve(graph,i,-1,1)) return false;
        }
        return true;
    }
    void print(int n){
        for(int i = 1;i <= n;i++){
            cout<< color[i] << " ";
        }
    }
};
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    for(int i = 0;i < m;i++){
        int a,b;
        cin >> a>> b;
        edges[i] = {a,b};
    }
    Solution code;
    if(code.possibleBipartition(n,edges)){
        code.print(n);
    }
    else{
        cout<<"IMPOSSIBLE";
    }
    return 0;
}
