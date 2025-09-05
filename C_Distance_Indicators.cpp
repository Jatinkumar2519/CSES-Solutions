#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    unordered_map<int, int> freq;
    long long ans = 0;

    for (int j = 0; j < n; j++) {
        int key = j - A[j];
        if (freq.count(key)) ans += freq[key];

        freq[j + A[j]]++;
    }

    cout << ans << '\n';
    return 0;
}
