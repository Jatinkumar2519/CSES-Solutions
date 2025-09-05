#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n,m) resize(n,m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;
const int MOD = 1e9 + 7;
long long powmod(long long a,long long b){
    long long res = 1;
    while(b > 0){
        if(b & 1){
           res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b = (b >> 1);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vl arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    ll res = 1;
    for(int i = 0;i < n;i++){
        if(res < arr[i]){
            break;
        }
        res += arr[i];
    }
    cout<< res;
    return 0;
}