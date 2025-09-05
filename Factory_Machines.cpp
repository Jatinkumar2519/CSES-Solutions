#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& arr,long long k,long long mid){
    long long count = 0;
    for(long long i : arr){
        count += (mid / i);
        if(count >= k) return true;
    }
    return false;
}
int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    long long left = 1;
    long long right = *max_element(arr.begin(),arr.end()) * k;
    long long time = right;
    while(left <= right){
        long long mid = (left + right) / 2;
        if(solve(arr,k,mid)){
            time = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    cout<< time;
    return 0;
}