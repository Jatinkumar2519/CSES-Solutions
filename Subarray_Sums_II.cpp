#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& arr,long long k){
    map<long long ,long long> map;
    map[0] = 1;
    long long sum = 0;
    long long count= 0;
    for(int i = 0;i < arr.size();i++){
        sum += arr[i];
        count += map[sum - k];
        map[sum]++;
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
    cout<< solve(arr,k);
    return 0;
}