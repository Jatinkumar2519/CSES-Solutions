#include <bits/stdc++.h>
# define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    vector<ll> dp;
    dp.push_back(arr[0]);
    for(int i = 1;i < n;i++){
        if(dp.back() < arr[i]){
            dp.push_back(arr[i]);
        }
        else{
            auto it = lower_bound(dp.begin(),dp.end(),arr[i]);
            *it = arr[i];
        }
    }
    cout<< dp.size();
    return 0;
}