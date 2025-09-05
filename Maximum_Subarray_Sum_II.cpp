#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,l,r;
    cin >> n >> l >> r;
    vector<ll> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    ll sum = 0;
    int left = 0;
    ll maxsum = LLONG_MIN;
    for(int i = 0;i < n;i++){
        sum += arr[i];
        while(r < (i - left + 1)){
            sum -= arr[left];
            left++;
        }
        if(l <= (i - left + 1) && (i - left + 1) <= r){
            maxsum = max(maxsum,sum);
        }
    }
    cout<< maxsum;
    return 0;
}