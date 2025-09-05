#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& arr,int n,int k){
    long long maxval = 0;
    long long curr = 0;
    for(int i = 0;i < k;i++){
        curr ^= arr[i];
    }
    maxval ^= curr;
    for(int i = k;i < n;i++){
        curr ^= arr[i - k];
        curr ^= arr[i];
        maxval ^= curr;
    }
    return maxval;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long long n,k;
    cin >> n >> k;
    vector<long long> arr(n);
    long long x,a,b,c;
    cin >> x >> a >> b >> c;
    arr[0] = x;
    for(int i = 1;i < n;i++){
        arr[i] = (a * arr[i - 1] + b) % c;
    }
    cout<< solve(arr,n,k);
    return 0;
}