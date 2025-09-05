#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& arr,int n){
    multiset<long long> set;
    for(int i = 0;i < n;i++){
        auto it = set.upper_bound(arr[i]);
        if(it != set.end()){
            set.erase(it);
        }
        set.insert(arr[i]);
    }
    return set.size();
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