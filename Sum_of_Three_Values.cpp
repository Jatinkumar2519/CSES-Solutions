#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll target;
    cin >> n >> target;

    const ll BASE = 200001;

    vector<ll> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] = arr[i] * BASE + (i + 1);
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++) {
        int l = i + 1, r = n - 1;
        while(l < r) {
            ll sum =
                arr[i] / BASE +
                arr[l] / BASE +
                arr[r] / BASE;

            if(sum == target) {
                vector<int> idx = {
                    (int)(arr[i] % BASE),
                    (int)(arr[l] % BASE),
                    (int)(arr[r] % BASE)
                };
                sort(idx.begin(), idx.end());
                for(int x : idx) cout << x << " ";
                return 0;
            }
            else if(sum < target) l++;
            else r--;
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}
