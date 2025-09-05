#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n,m) resize(n,m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;
const int MOD = 1e9 + 7;
// long long powmod(long long a,long long b){
//     long long res = 1;
//     while(b > 0){
//         if(b & 1){
//            res = (res * a) % MOD;
//         }
//         a = (a * a) % MOD;
//         b = (b >> 1);
//     }
//     return res;
// }
vector<int> parent,ranks;
int find(int num){
    if(num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}
void Union(int a,int b){
    int n1 = find(a);
    int n2 = find(b);
    if(n1 == n2) return;
    if(ranks[n1] < ranks[n2]){
        parent[n1] = n2;
    }
    else if(ranks[n1] > ranks[n2]){
        parent[n2] = n1;
    }
    else{
        ranks[n1]++;
        parent[n2] = n1;
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    parent.resize(n + 1);
    ranks.resize(n + 1);
    for(int i = 1;i <= n;i++){
        parent[i] = i;
    }
    for(int i = 1;i <= n;i++){
        parent[i] = i;
    }
    for(int i = 0;i < m;i++){
        int a,b;
        cin >> a >> b;
        Union(a,b);
    }
    unordered_set<int> sett;
    for(int i = 1;i <= n;i++){
        sett.insert(find(i));
    }
    vector<int> component(sett.begin(),sett.end());
    cout<< component.size() - 1 << endl;
    for(int i = 0;i < component.size() - 1;i++){
        cout<< component[i] << " " << component[i + 1]<<endl;
    }
    return 0;
}