#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& arr,int k,int n){
    map<long long,int> map;
    int left = 0;
    long long count = 0;
    for(int i = 0;i < n;i++){
        map[arr[i]]++;
        while(left < i && map.size() * 1LL > k){
            if(--map[arr[left]] == 0){
                map.erase(arr[left]);
            }
            left++;
        }
        count += (i - left + 1);
    }
    return count;
}
int main() {
    int n,k;
    cin >> n >> k;
    vector<long long> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    cout<< solve(arr,k,n);
    return 0;
}