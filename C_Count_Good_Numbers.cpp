#include<bits/stdc++.h>
using namespace std;
long long count_divisible(long long l, long long r, long long p) {
    return r / p - (l - 1) / p;
}

long long count_good(long long l, long long r) {
    vector<int> primes = {2, 3, 5, 7};
    int n = primes.size();
    long long total = r - l + 1;
    long long bad = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        long long lcm = 1;
        int bits = __builtin_popcount(mask);

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                lcm = lcm * primes[i] / __gcd(lcm, (long long)primes[i]);
                if (lcm > r) break;
            }
        }
        if (lcm > r) continue;

        long long cnt = count_divisible(l, r, lcm);
        if (bits % 2 == 1) bad += cnt;
        else bad -= cnt;
    }

    return total - bad;
}
int main(){
    int tt;
    cin >> tt;
    while(tt--){
        long long a,b;
        cin >> a >> b;
        cout<< count_good(a,b) << endl;
    }
}
