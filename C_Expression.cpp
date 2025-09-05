#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    cout<< max({(a + b) * c,(b + c) * a,a + b + c,a * b * c});
    return 0;
}