#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> learned(n + 1);
    vector<vector<int>> graph(n + 1);
    vector<int> A(n + 1),B(n + 1);
    for(int i = 1;i <= n;i++){
        cin >> A[i] >> B[i];
        if(A[i] == 0 && B[i] == 0){
            learned[i] = 1;
        }
        else{
            graph[A[i]].push_back(i);
            graph[B[i]].push_back(i);
        }
    }
    queue<int> q;
    for(int i = 1;i <= n;i++){
        if(learned[i]){
            q.push(i);
        }
    }
    int count = 0;
    while(!q.empty()){
        int node = q.front();q.pop();
        count++;
        for(int nn : graph[node]){
            if(!learned[nn]){
                learned[nn] = 1;
                q.push(nn);
            }
        }
    }
    cout<< count ;
    return 0;
}