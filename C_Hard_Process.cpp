#include <bits/stdc++.h>
using namespace std;

pair<int,int> solve(vector<int>& arr,int k){
    int left = 0;
    int maxlen = 0;
    int sum = 0;
    int indx = 0;
    for(int i = 0;i < arr.size();i++){
        sum += arr[i];
        while(left < i && (i - left + 1) - sum > k){
            if(arr[left] == 1){
                sum --;
            }
            left ++;
        }
        if ((i - left + 1) - sum <= k && maxlen < (i - left + 1)) {
            maxlen = i - left + 1;
            indx = left;
        }
    }
    return {indx,maxlen};
}
int main() {
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    auto pair = solve(arr,k);
    int indx = pair.first;
    int maxlen = pair.second;
    cout<< maxlen << endl;
    for(int i = indx;i < indx + maxlen;i++){
        arr[i] = 1;
    }
    for(int i : arr){
        cout<< i <<" ";
    }
    return 0;
}