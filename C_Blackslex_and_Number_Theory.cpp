#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        int n ;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0;i < n;i++){
            cin >> arr[i];
        }
        int m = *min_element(arr.begin(),arr.end());
        int gcd = 0;
        for(int i = 0;i < n;i++){
            gcd = __gcd(gcd,arr[i] - m);
        }
        cout<< gcd << endl;
    }
    return 0;
}