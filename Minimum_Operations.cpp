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
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<ll> arr(n);
        for(int i = 0;i < n;i++){
            cin >> arr[i];
        }
        int two = 0,one = 0;
        for(ll num : arr){
            if(num < 0) two++;
            else one++;
        }
        
    }
    return 0;
}