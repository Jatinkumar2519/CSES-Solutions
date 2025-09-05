#include <bits/stdc++.h>
using namespace std;
struct DSU{
    vector<int> parent,rank;
    DSU(int n){
        parent.reserve(n);
        rank.resize(n,0);
        for(int i = 0;i < n;i++){
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
int main() {
    int n,m;
    cin >> n >> m;
    DSU code = DSU(n + 1);
    for(int i = 0;i < m;i++){
        string work;
        int num1,num2;
        cin >> work >> num1 >> num2;
        if(work == "union"){
            code.Union(num1,num2);
        }
        else{
            if(code.Find(num1) == code.Find(num2)){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}