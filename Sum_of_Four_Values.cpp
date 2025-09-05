#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<long long>& arr, int n, long long target) {
    vector<pair<long long, int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back({arr[i], i});
    }
    sort(v.begin(), v.end());
    for(int i = 0;i < n - 2;i++){
        for(int j = i + 1;j < n - 1;j++){
            int left = j + 1,right = n - 1;
            while(left < right){
                long long sum = v[i].first + v[j].first + v[left].first + v[right].first;
                if(sum == target){
                    return {v[i].second,v[j].second,v[left].second,v[right].second};
                }
                if(sum > target){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
    }
    return {};
}

int main() {
    int n;
    long long target;
    cin >> n >> target;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    auto res = solve(arr, n, target);
    if(res.empty()) cout<< "IMPOSSIBLE";
    else{
        sort(res.begin(),res.end());
        for(int i : res){
            cout<< i + 1 << ' ';
        }
    }
    return 0;
}
