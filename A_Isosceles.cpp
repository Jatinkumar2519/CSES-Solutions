#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int a,b,c;
    cin >> a >> b >> c;
    if((a == b && b == c) || (a == b) || (b == c) || (a == c)) cout << "Yes";
    else cout << "No";
    return 0;
}