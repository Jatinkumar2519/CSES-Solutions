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
    int tt;
    cin >> tt;
    while(tt--){
        ll num1,num2;
        cin >> num1 >> num2;
        cout<< powmod(num1,num2) << endl;
    }
    return 0;
}