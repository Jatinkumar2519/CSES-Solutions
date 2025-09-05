#include <bits/stdc++.h>
using namespace std;
long long solve(vector<long long>& arr,int n){
    sort(arr.begin(),arr.end());
    long long num = arr[n/2];
    long long count = 0;
    for(long long i : arr){
        count += abs(i - num);
    }
    return count;
}
int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    cout<< solve(arr,n);
    return 0;
}