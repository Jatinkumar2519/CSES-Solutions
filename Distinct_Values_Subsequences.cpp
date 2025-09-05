#include <bits/stdc++.h>
using namespace std;
long long power(long long a,long long x,int mod){
    long long res = 1;
    a %= mod;
    while(x > 0){
        if(x & 1){
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        x = (x >> 1);
    }
    return res;
}
long long solve(vector<long long>& arr,int n){
    map<long long,int > map;
    int mod = 1e9 + 7;
    for(long long i : arr){
        map[i]++;
    }
    int len = map.size();
    long long count = power(2,len,mod) - 1;
    long long p = power(2,len - 1,mod);
    for(auto temp : map){
        if(temp.second > 1){
            count = ((count + p) * (temp.second - 1)) % mod;
        }
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