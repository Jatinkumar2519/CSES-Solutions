#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    ll num,x;
    cin >> num >> x;
    cout<< (((num * 1000) / (1000 + x)) / 1000) * 1000 ;
    return 0;
}