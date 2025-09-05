#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n,m) resize(n,m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;
const int MOD = 1e9 + 7;
// long long powmod(long long a,long long b){
//     long long res = 1;
//     while(b > 0){
//         if(b & 1){
//            res = (res * a) % MOD;
//         }
//         a = (a * a) % MOD;
//         b = (b >> 1);
//     }
//     return res;
// }

// int solve(){

// }
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        int n ;
        cin >> n;
        vector<int> arr(n);
        vector<int> res(n);
        for(int i = 0;i < n;i++){
            cin >> arr[i];
            res[i] = i + 1;
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n - 1;j++){
                if((arr[j] + res[j]) > (arr[j + 1] + res[j + 1])){
                    swap(res[j],res[j + 1]);
                }
            }
        }
        for(int i : res){
            cout<< i << ' ';
        }
        cout<< endl;
    }
    return 0;
}