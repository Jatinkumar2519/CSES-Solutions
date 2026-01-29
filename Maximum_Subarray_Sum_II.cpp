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

    ll sum = 0,maxv = LLONG_MIN;
    int left = 0;
    for(int i = 0;i < n;i++){
        if(arr[i] > arr[i] + sum){
            left = i;
            sum = arr[i];
        }
        else{
            sum += arr[i];
        }

        if(i - left + 1 > r){
            sum -= arr[left++];
        }
        
        if(i - left + 1 >= l){
            maxv = max(maxv,sum);
        }
    }
    cout<< maxv;
    return 0;
}