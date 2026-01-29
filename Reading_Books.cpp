#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n ; cin >> n;
    vector<ll> arr(n);

    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    sort(arr.begin(),arr.end());
    ll right = arr.back();
    ll sum = accumulate(arr.begin(),arr.end() - 1,0LL);

    if(right <= sum){
        cout<< right + sum;
    }
    else{
        cout<< 2 * right;
    }
    return 0;
}