#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        int n,m;
        cin >> n >> m;
        if(m % 2 == 0){
            cout<< 0 << endl;
        }
        else{
            cout<< n << endl;
        }
    }
    return 0;
}