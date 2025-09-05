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
ll dp[20][10][2][2];
ll solve(string& num,int pos,int prev,int tight,int leading_zeroes){
    if(pos == num.length()) return leading_zeroes == 0;
    if(dp[pos][prev][tight][leading_zeroes] != -1) return dp[pos][prev][tight][leading_zeroes];
    ll res = 0;
    int limit = (tight ? (num[pos] - '0') : 9);
    for(int d = 0;d <= limit;d++){
        if(leading_zeroes || prev != d){
            res += solve(num,pos + 1,d,tight && (d == limit),leading_zeroes && (d == 0));
        }
    }
    return dp[pos][prev][tight][leading_zeroes] = res; 
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll a,b;
    cin >> a >> b;
    string num1 = to_string((a > 0) ? a - 1 : a);
    string num2 = to_string(b);
    memset(dp,-1,sizeof(dp));
    ll res = solve(num2,0,0,1,1);
    memset(dp,-1,sizeof(dp));
    res -= solve(num1,0,0,1,1);
    if(a == 0)
        res++;
    cout<< res;
    return 0;
}