#include <bits/stdc++.h>
using namespace std;
bool check(vector<long long>& arr,int n,long long k,long long mid){
    long long count = 1;
    long long prev = arr[0];
    for(int i = 1;i < n;i++){
        if(arr[i] - prev >= mid){
            prev = arr[i];
            count++;
            if(count >= k) return true;
        }
    }
    return false;
}
void solve(){
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    long long left = 1;
    long long right = arr[n - 1] - arr[0];
    long long maxval = 1;
    while (left <= right)
    {
        long long mid = (left + right)/2;
        if(check(arr,n,k,mid)){
            maxval = mid;
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    cout<< maxval << endl;
}
int main() {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        solve();
    }
    return 0;
}