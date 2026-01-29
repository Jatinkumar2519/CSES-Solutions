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
        for(int i = 0; i < n;i++){
            cin >> arr[i];
        }

        bool even = true;
        bool odd = true;

        for(int i = 0;i < n;i += 2){
            even = even & (arr[i] % 2 == 0);
            odd = odd & (arr[i] % 2 == 1);
        }
        if(even || odd){
            cout<< "YES" << endl;
        }
        else{
            cout<< "NO" << endl;
        }
    }
    return 0;
}