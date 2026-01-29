#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    vector<int> nums;
    unordered_map<int,int> mapp;
    for(int i = 0;i < n;i++){
        if(nums.empty() || nums.back() != arr[i]){
            nums.push_back(arr[i]);
        }
    }
    ll len = nums.size();
    ll count = (len * (len - 1)) / 2 + 1;
    for(int& num : nums){
        mapp[num]++;
    }
    for(auto& [_,cnt] : mapp){
        count -= (cnt * (cnt - 1))/2;
    }
    cout<< count;
    return 0;
}