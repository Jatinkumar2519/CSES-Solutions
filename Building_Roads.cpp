#include <bits/stdc++.h>
using namespace std;
class DSU{
    public:
    vector<int> parent,rank;
    DSU(){}
    DSU(int n){
        parent.resize(n + 1);
        rank.resize(n + 1,0);
        for(int i = 1;i <= n;i++){
            parent[i] = i;
        }
    }
    int find(int num){
        if(num == parent[num]){
            return num;
        }
        return parent[num] = find(parent[num]);
    }
    void Union(int num1,int num2){
        int p1 = find(num1);
        int p2 = find(num2);
        if(p1 == p2) return;
        if(rank[p1] > rank[p2]){
            parent[p2] = p1;
        }
        else if(rank[p1] < rank[p2]){
            parent[p1] = p2; 
        }
        else{
            rank[p1]++;
            parent[p2] = p1;
        }
    }
};
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    DSU code(n);
    for(int i = 0;i < m;i++){
        int a,b;
        cin >> a >> b;
        code.Union(a,b);
    }
    unordered_set<int> set;
    for(int i = 1;i <= n;i++){
        set.insert(code.find(i));
    }
    cout<< set.size() - 1 << endl;
    vector<int> road(set.begin(),set.end());
    for(int i = 0;i < road.size() - 1;i++){
        cout<< road[i] << " " << road[i + 1]<<endl;
    }
    return 0;
}