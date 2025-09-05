#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n, m) resize(n, m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        long long n;
        cin >> n;

        vector<long long> answers;

        // check for k >= 1 such that (10^k + 1) divides n
        long long ten_pow = 10;
        for (int k = 1;; k++)
        {
            long long d = ten_pow + 1; // denominator = 10^k + 1
            if (d > n)
                break; // no need to check further
            if (n % d == 0)
            {
                answers.push_back(n / d);
            }
            // prepare next power of 10
            if (ten_pow > n / 10)
                break; // avoid overflow
            ten_pow *= 10;
        }

        if (answers.empty())
        {
            cout << 0 << "\n"; // no valid x
        }
        else
        {
            cout<< answers.size() << endl;
            sort(answers.begin(),answers.end());
            for (long long x : answers)
                cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}