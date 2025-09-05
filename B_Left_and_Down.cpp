#include <bits/stdc++.h>
using namespace std;
int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        long long a, b, k;
        cin >> a >> b >> k;
        long long g = __gcd(a, b);
        if (a / g <= k && b / g <= k)
            cout << 1 << '\n';
        else 
            cout << 2 << '\n';
    }
    return 0;
}
