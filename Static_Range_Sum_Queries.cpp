#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;

    vector<ll> arr(n + 1,0);
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
    }

    for(int i = 1;i <= n;i++){
        arr[i] += arr[i - 1];
    }

    for(int i = 0;i < m;i++){
        int l,r;
        cin >> l >> r;
        
        cout<< arr[r] - arr[l - 1] << endl;
    }
    return 0;
}