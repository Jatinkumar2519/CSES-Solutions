#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n,m) resize(n,m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;
const int MOD = 1e9 + 7;
int n,m,k;
struct WhiteDSU{
    vector<int> parent,rank;
    WhiteDSU(int n){
        rank.resize(n + 1);
        parent.resize(n + 1);
        for(int i = 1;i <= n;i++){
            parent[i] = i;
        }
    }
    int find(int num){
        if(parent[num] == num){
            return num;
        }
        return parent[num] = find(parent[num]);
    }
    void Union(int n1,int n2){
        int p1 = find(n1);
        int p2 = find(n2);
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
struct BlackDSU{
    vector<int> parent,rank;
    BlackDSU(int n){
        rank.resize(n + 1);
        parent.resize(n + 1);
        for(int i = 1;i <= n;i++){
            parent[i] = i;
        }
    }
    int find(int num){
        if(parent[num] == num){
            return num;
        }
        return parent[num] = find(parent[num]);
    }
    void Union(int n1,int n2){
        int p1 = find(n1);
        int p2 = find(n2);
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
    cin >> n >> m >> k;
    WhiteDSU white_dsu(n);
    BlackDSU black_dsu(n);
    for(int i = 0;i < m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(c)
            white_dsu.Union(a,b);
        else
            black_dsu.Union(a,b);
    }
    for(int i = 0;i < k;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int p_a = white_dsu.find(a);
        int p_b = white_dsu.find(b);
        int p_c = white_dsu.find(c);
        int p_d = white_dsu.find(d);
        if(p_a == p_b && p_c != p_d) cout<< "Yes" << endl;
        else cout<< "No" << endl;
    }
    return 0;
}