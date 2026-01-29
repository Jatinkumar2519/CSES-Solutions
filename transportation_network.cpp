#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

struct DSU{
    vector<int> parent,rank;
    DSU(int n){
        parent = vector<int>(n + 1);
        rank = vector<int>(n + 1);
        for(int i = 1;i <= n;i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int find(int num){
        if(parent[num] == num) return num;
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
            rank[p2]++;
            parent[p1] = p2;
        }
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;

    DSU roads(n),train(n);
    for(int i = 0;i < m;i++){

        int t,u,v;
        cin >> t >> u >> v;

        if(t == 1){
            train.Union(u,v);
        }
        else{
            roads.Union(u,v);
        }

        bool flag = true;
        for(int p = 1;p <= n && flag;p++){
            for(int q = i + 1;q <= n && flag;q++){
                if((train.find(p) == train.find(q)) ^ (roads.find(p) == roads.find(q))){
                    flag = false;
                }
            }
        }
        
        if(flag){
            cout<< "Yes" << endl;
        }
        else{
            cout<< "No" << endl;
        }
    }
    return 0;
}