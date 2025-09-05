#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long long n,k;
    cin >> n >> k;
    vector<long long> arr(n);
    for(long long i = 0;i < n;i++){
        cin >> arr[i];
    }
    multiset<long long> set(arr.begin(),arr.end());
    long long t = 0;
    while(set.size() > 1 && *set.begin() < k){
        long long num1 = *set.begin();set.erase(set.begin());
        long long num2 = *set.begin();set.erase(set.begin());
        long long num = num1 + (2 * num2);
        set.insert(num);
        t++;
    }
    if(set.size() <= 1 && *set.begin() < k){
        cout<< -1;
        return 0;
    }
    cout<< t;
    return 0;
}