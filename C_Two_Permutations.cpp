#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    bool res = (a == n && b == n) || (a + b + 1 < n);
    string ans =  (res == 1) ? "Yes" : "No" ;
    cout<< ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
