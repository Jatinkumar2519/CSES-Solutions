#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    
    vector<ll> arr_diff(n + 2,0);
    vector<ll> arr(n + 1);
    
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
    }
    
    vector<tuple<int,int,ll>> query(m + 1);
    for(int i = 1;i <= m;i++){
        int l,r;
        ll d;
        cin >> l >> r >> d;
        query[i] = make_tuple(l,r,d);
    }
    
    vector<ll> queries_diff(m + 2,0);
    for(int i = 0;i < k;i++){
        int l,r;
        cin >> l >> r;
        queries_diff[l] += 1;
        queries_diff[r + 1] -= 1;
    }

    for(int i = 1;i <= m;i++){
        queries_diff[i] += queries_diff[i - 1];
    }

    for(int i = 1;i <= m;i++){
        int times = queries_diff[i];

        auto [l,r,d] = query[i];
        arr_diff[l] += times * d;
        arr_diff[r + 1] -= times * d;
    }

    for(int i = 1;i <= n;i++){
        arr_diff[i] += arr_diff[i - 1];
    }

    for(int i = 1;i <= n;i++){
        cout<< arr_diff[i] + arr[i] << ' ';
    }
    return 0;
}