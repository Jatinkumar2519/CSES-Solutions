#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& arr,long long k){
    long long n = arr.size();
    map<long long,long long> map; map[0] = 1;
    long long count = 0;
    long long sum = 0;
    for(long long i = 0;i < n;i++){
        sum += arr[i];
        long long mod = ((sum % n) + n) % n;
        count += map[mod];
        map[mod]++;
    }
    return count;
}
int main() {
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for(long long i = 0;i < n;i++){
        cin >> arr[i];
    }
    cout<< solve(arr,n);
    return 0;
}