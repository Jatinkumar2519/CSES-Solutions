#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n,m) resize(n,m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    ll sum = arr.back();
    ll prev = arr.back();
    for(int i = n - 2;i >= 0;i--){
        if(arr[i] == 0) continue;
        if(arr[i] < prev){
            sum += arr[i];
            prev = arr[i];
        }
        else{
            sum += max(prev - 1,0LL);
            prev = prev - 1;
        }
    }
    cout<< sum;
    return 0;
}