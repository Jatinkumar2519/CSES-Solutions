#include <bits/stdc++.h>
using namespace std;
int solve(vector<long long>& arr,long long curr,long long mask,long long i,long long total){
    long long n = arr.size();
    if(i == n){
        if(__builtin_popcount(mask) == arr.size()){
            return 0;
        }
        return 1 + solve(arr,0,mask,0,total);
    }
    if((mask & (1 << i))){
        return solve(arr,curr,mask,i + 1,total);
    }
    int minv = INT_MAX;
    minv = min(minv,solve(arr,curr,mask,i + 1,total));
    if(curr + arr[i] <= total){
        minv = min(minv,solve(arr,curr + arr[i],mask | (1 << i),i + 1,total));
    }
    return minv;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long long n;
    long long capacity;
    cin >> n >> capacity;
    vector<long long> arr(n);
    for(long long i = 0;i < n;i++){
        cin >> arr[i];
    }
    cout<< solve(arr,0,0,0,capacity);
    return 0;
}