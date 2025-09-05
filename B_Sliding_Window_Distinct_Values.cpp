#include <bits/stdc++.h>
using namespace std;

void solve(vector<long long>& arr,long long n,long long k){
    map<long long,int> map;
    for(long long i = 0;i < k;i++){
        map[arr[i]]++;
    }
    cout << map.size() << ' ';
    for(long long i = k;i < n;i++){
        if(--map[arr[i - k]] == 0){
            map.erase(arr[i - k]);
        }
        map[arr[i]]++;
        cout<< map.size() <<' ';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long long n,k;
    cin >> n >> k;
    vector<long long> arr(n);
    for(long long i = 0;i < n;i++){
        cin >> arr[i];
    }
    solve(arr,n,k);
    return 0;
}