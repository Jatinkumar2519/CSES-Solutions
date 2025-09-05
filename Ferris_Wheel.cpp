#include <bits/stdc++.h>
# define ll long long
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    ll k;
    cin >> n >> k;
    vector<long long> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    int left = 0;
    int right = n - 1;
    int count = 0;
    while(left <= right){
        if(arr[left] + arr[right] <= k){
            left ++;
            right --;
        }
        else{
            right --;
        }
        count++;
    }
    cout<< count;
    return 0;
}