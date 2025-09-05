#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& arr1,vector<long long>& arr2,long long k){
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    long long count = 0;
    long long i = 0,j = 0;
    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i] - k <= arr2[j] && arr2[j] <= arr1[i] + k){
            count++;i++;j++;
        }
        else if(arr2[j] < arr1[i] - k){
            j++;
        }
        else{
            i++;
        }
    }
    return count;
}
int main() {
    long long n,m,k;
    cin >> n >> m >> k;
    vector<long long> arr1(n),arr2(m);
    for(long long i = 0;i < n;i++){
        cin >> arr1[i];
    }
    for(long long i = 0;i < n;i++){
        cin >> arr2[i];
    }
    cout<< solve(arr1,arr2,k);
    return 0;
}