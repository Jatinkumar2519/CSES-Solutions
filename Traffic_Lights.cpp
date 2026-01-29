#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int len,n;
    cin >> len >> n;

    vector<int> cuts(n);
    for(int i = 0;i < n;i++){
        cin >> cuts[i];
    }

    set<int> positions;
    multiset<int> lengths;

    positions.insert(0);
    positions.insert(len);

    lengths.insert(len);

    for(int i = 0;i < n;i++){
        auto it = positions.lower_bound(cuts[i]);

        int right = *it;
        int left = *prev(it);

        positions.insert(cuts[i]);

        lengths.erase(lengths.find(right - left));

        lengths.insert(cuts[i] - left);
        lengths.insert(right - cuts[i]);

        cout<< *lengths.rbegin() << ' ';
    }
    return 0;
}