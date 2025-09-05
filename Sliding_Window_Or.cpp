#include <bits/stdc++.h>
using namespace std;
long long solve(long long arr[],long long n,long long k){
    vector<long long> bit(64,0);
    long long res = 0;
    long long curr = 0;
    for(long long i = 0;i < k;i++){
        curr |= arr[i];
        for(int j = 0;j < 64;j++){
            if(arr[i] & (1LL << j)){
                bit[j]++;
            }
        }
    }
    res ^= curr;
    for(long long i = k;i < n;i++){
        long long num = arr[i - k];
        for(int j = 0;j < 64;j++){
            if(num & (1LL << j)){
                if(--bit[j] == 0){
                    curr = (curr & ~(1LL << j));
                }
            }
        }
        for(int j = 0;j < 64;j++){
            if(arr[i] & (1LL << j)){
                bit[j]++;
            }
        }
        curr |= arr[i];
        res ^= curr;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long long n,k;
    cin >> n >> k;
    long long arr[n];
    memset(arr,0,sizeof(arr));
    long long x,a,b,c;
    cin >> x >> a >> b >> c;
    arr[0] = x;
    for(long long i = 1;i < n;i++){
        arr[i] = (((a % c) * (arr[i - 1] % c)) % c + b % c) % c;
    }
    cout<< solve(arr,n,k);
    return 0;
}