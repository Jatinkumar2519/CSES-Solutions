#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n,m) resize(n,m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        ll x;
        cin >> n >> x;
        vector<ll> arr(n);
        for(int i = 0;i < n;i++){
            cin >> arr[i];
        }
        int count = 0;
        int j = n - 1;
        sort(arr.begin(),arr.end());
        for(int i = n - 1;i >= 0;i--){
            if(arr[i] * (j - i + 1) >= x){
                count++;
                j = i - 1;
            }
        }
        cout<< count << endl;
    }
    return 0;
}