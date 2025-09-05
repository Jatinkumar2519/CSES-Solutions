#include <bits/stdc++.h>
using namespace std;

void solve(vector<long long>& arr,int n){
    long long maxsum = INT_MIN;
    long long sum = 0;
    for(int i = 0;i < n;i++){
        sum = max(sum + arr[i],arr[i]);
        maxsum = max(maxsum,sum);
    }
    cout<< maxsum;
}
int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    solve(arr,n);
    return 0;
}