#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<ll> arr(n),prefix(n,0);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    prefix[0] = arr[0];
    for(int i = 1;i < n;i++){
        prefix[i] = prefix[i - 1] + arr[i];
    }
    int shift = 0;
    for(int i = 0;i < m;i++){
        int t;
        cin >> t;
        if(t == 1){
            int s;
            cin >> s;
            shift = (shift + s) % n;
        }
        else{
            int l,r;
            cin >> l >> r;
            l--;r--;
            l = (shift + l) % n;
            r = (shift + r) % n;
            ll res = 0;
            if(l <= r){
                if(l == 0){
                    res = prefix[r];
                }
                else{
                    res = prefix[r] - prefix[l - 1];
                }
            }
            else{
                res += prefix[n - 1] - prefix[l - 1];
                res += prefix[r];
            }
            cout<< res << endl;
        }
    }
    return 0;
}