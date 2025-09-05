#include <bits/stdc++.h>
using namespace std;
bool check(vector<long long>& arr,int k,long long mid){
    long long sum = 0;
    int count = 1;
    for(auto& i : arr){
        if(i > mid){
            return false;
        }
        if(sum + i > mid){
            count++;
            sum = 0;
        }
        sum += i;
    }
    return count <= k;
}
long long solve(vector<long long>& arr,int n,int k){
    long long left = *max_element(arr.begin(),arr.end());
    long long right = accumulate(arr.begin(),arr.end(),0LL);
    long long minv = left;
    while(left <= right){
        long long mid = left + (right - left)/2;
        if(check(arr,k,mid)){
            minv = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return minv;
}
int main() {
    int n,k;
    cin >> n >> k;
    vector<long long> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    cout<< solve(arr,n,k);
    return 0;
}