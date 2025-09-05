#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n,m) resize(n,m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<ll, int> map1;           // element -> frequency
    map<int, set<ll>> map2;                // frequency -> set of elements

    // Initialize first window
    for (int i = 0; i < k; i++) {
        int freq = map1[arr[i]];
        if (freq > 0)
            map2[freq].erase(arr[i]);
        map1[arr[i]]++;
        map2[freq + 1].insert(arr[i]);
    }

    // Output result for first window
    cout << *map2.rbegin()->second.begin() << ' ';

    // Slide the window
    for (int i = k; i < n; i++) {
        ll out = arr[i - k];
        ll in = arr[i];

        // Remove outgoing element
        int freqOut = map1[out];
        map2[freqOut].erase(out);
        if (map2[freqOut].empty()) map2.erase(freqOut);

        map1[out]--;
        if (map1[out] > 0)
            map2[map1[out]].insert(out);
        else
            map1.erase(out);

        // Add incoming element
        int freqIn = map1[in];
        if (freqIn > 0)
            map2[freqIn].erase(in);
        map1[in]++;
        map2[freqIn + 1].insert(in);

        // Output result
        cout << *map2.rbegin()->second.begin() << ' ';
    }

    return 0;
}
