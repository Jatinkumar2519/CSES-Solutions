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
int n;
vector<int> connectedComponents(vector<vector<int>> edges){
    parent.resize(2 * (n + 1));
    ranks.resize(2 * (n + 1));
    for(int i = 1;i < 2*(n + 1);i++){
        parent[i] = i;
    }
    for(auto edge : edges){
        int a = edge[0];
        int b = edge[1];
        Union(a,b);
    }
    vector<int> sizes(2* (n + 1));
    for(int i = 1;i < 2*(n + 1);i++){
        sizes[find(i)]++;
    }
    int minSize = INT_MAX, maxSize = 0;
    for(int sz : sizes){
        if(sz > 1){
            minSize = min(minSize, sz);
            maxSize = max(maxSize, sz);
        }
    }
    return {minSize, maxSize};
}
int main(){
    cin >> n;
    vector<vector<int>> edges;
    for(int i = 0;i < n;i++){
        int a ,b;
        cin >> a >> b;
        edges.push_back({a,b});
    }
    vector<int> res = connectedComponents(edges);
    cout<< res[0] << " " << res[1];
    return 0;
}