#include <bits/stdc++.h>
using namespace std;

void solve(vector<long long>& arr,long long n){
    stack<long long> s;
    vector<long long> res(n,0);
    for(long long i = 0;i < n;i++){
        while(!s.empty() && arr[s.top()] >= arr[i]){
            s.pop();
        }
        if(!s.empty()){
            res[i] = s.top() + 1;
        }
        s.push(i);
    }
    for(long long i : res){
        cout<< i << " ";
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    solve(arr,n);
    return 0;
}