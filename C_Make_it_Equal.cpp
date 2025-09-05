#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n,m) resize(n,m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;
bool find(ll x,ll y,ll target){
    int left = 0;
    int right = 200000;
    while(left <= right){
        ll mid = (left + right) / 2;
        ll num = x + mid * y;
        if(num == target){
            return true;
        }
        else if(num < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        ll k;
        cin >> n >> k;
        
    }
    return 0;
}