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
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int m;
    string str;
    cin >> str;
    int n = str.length();
    vector<int> arr(n + 1);
    cin >> m;
    for(int i = 0;i < m;i++){
        int a;
        cin >> a;
        int b = n - a + 1;
        arr[a - 1] ++;
        arr[b] --;
    }
    for(int i = 1;i < n;i++){
        arr[i] += arr[i - 1];
    }
    int left = 0,right = n - 1;
    while(left < right){
        if(arr[left] % 2 == 1 && arr[right] % 2 == 1){
            swap(str[left++],str[right--]);
        }
        else if(arr[left] % 2 == 0) left++;
        else right--;
    }
    cout<< str;
    return 0;
}