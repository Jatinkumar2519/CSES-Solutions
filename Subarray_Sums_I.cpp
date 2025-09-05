#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& arr,long long k,int n){
    int left = 0;
    long long count = 0;
    long long sum = 0;
    for(int i = 0;i < n;i++){
        sum += arr[i];
        while(left < i && sum > k){
            sum -= arr[left];
            left++;
        }
        if(sum == k) count++;
    }
    return count;
}
int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    cout<< solve(arr,k,n);
    return 0;
}