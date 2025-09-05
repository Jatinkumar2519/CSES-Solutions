#include <bits/stdc++.h>
#define ll long long
using namespace std;

// Custom comparator: sort by a ascending, then b descending
static bool cmp(tuple<ll, ll, int>& a, tuple<ll, ll, int>& b) {
    if (get<0>(a) == get<0>(b))
        return get<1>(a) > get<1>(b);
    return get<0>(a) < get<0>(b);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;

    vector<pair<ll, ll>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    vector<tuple<ll, ll, int>> sorted(n);
    for (int i = 0; i < n; i++) {
        sorted[i] = {arr[i].first, arr[i].second, i};
    }
    sort(sorted.begin(), sorted.end(), cmp);

    vector<bool> contains(n, false), contained(n, false);
    ll max_b = -1;
    for (int i = 0; i < n; i++) {
        ll b = get<1>(sorted[i]);
        int idx = get<2>(sorted[i]);
        if (b <= max_b) {
            contained[idx] = true;
        }
        max_b = max(max_b, b);
    }

    ll min_b = LLONG_MAX;
    for (int i = n - 1; i >= 0; i--) {
        ll b = get<1>(sorted[i]);
        int idx = get<2>(sorted[i]);
        if (b >= min_b) {
            contains[idx] = true;
        }
        min_b = min(min_b, b);
    }

    // Output
    for (bool x : contains) cout << x << ' ';
    cout << '\n';
    for (bool x : contained) cout << x << ' ';
    cout << '\n';

    return 0;
}
