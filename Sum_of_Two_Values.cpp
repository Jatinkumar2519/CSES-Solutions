#include <bits/stdc++.h>
using namespace std;

void solve(vector<long long>& arr,long long k){
    map<long long,int> map;
    for(int i = 0;i < arr.size();i++){
        if(map.find(k - arr[i]) != map.end()){
            cout<< map[k - arr[i]] + 1 <<" "<<i + 1;
            return;
        }
        map[arr[i]] = i;
    }
    cout<< "IMPOSSIBLE";
}
int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    solve(arr,k);
    return 0;
}