#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& arr,int n){
    map<long long,int> map;
    long long count = 0;
    int left = 0;
    for(int i = 0;i < n;i++){
        map[arr[i]]++;
        while(map[arr[i]] > 1){
            if(--map[arr[left]] == 0){
                map.erase(arr[left]);
            }
            left++;
        }
        count += map.size();
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