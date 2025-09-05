#include <bits/stdc++.h>
#define vvi vector<vector<int>>
#define vi vector<int>
using namespace std;
class DSU{
public:
    vi parent,rank;
    DSU(int n){
        parent.reserve(n + 1);
        rank.resize(n + 1,0);
        for(int i = 1;i <= n;i++){
            parent[i] = i;
        }
    }
    int Find(int num){
        if(parent[num] == num){
            return num;
        }
        return parent[num] = Find(parent[num]);
    }
    void Union(int num1,int num2){
        int par1 = Find(num1);
        int par2 = Find(num2);
        if(par1 == par2) return;
        if(rank[par1] > rank[par2]){
            parent[par2] = par1;
        }
        else if(rank[par1] < rank[par2]){
            parent[par1] = par2;
        }
        else{
            rank[par1]++;
            parent[par2] = par1;
        }
    }
};
int Door_ki_Pedaiyesh(vector<vector<int>>& graph,int root,int n){
    vi degree(n + 1,0);
    
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vvi graph(n);
    DSU dsu(n);
    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin >> a >> b;
        dsu.Union(a,b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    unordered_set<int> roots;
    for(int i = 1;i <= n;i++){
        roots.insert(dsu.Find(i));
    }
    return 0;
}