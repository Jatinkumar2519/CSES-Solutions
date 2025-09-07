#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        ll a,b,c;
        cin >> a >> b >> c;
        ll org = min({a,c,b});
        a -= org;b -= org;c -= org;
        cout<< org + max(min(a/2,c),min(a,c/2)) << endl;
    }
    return 0;
}