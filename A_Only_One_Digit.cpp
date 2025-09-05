#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        int minv = 10;
        while (n > 0)
        {
            minv = min(minv, n % 10);
            n /= 10;
        }
        cout << minv << endl;
    }
    return 0;
}