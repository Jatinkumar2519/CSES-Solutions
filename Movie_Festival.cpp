#include <bits/stdc++.h>
using namespace std;

static bool cmp(pair<long long, long long>& a, pair<long long, long long>& b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int solve(vector<pair<long long, long long>>& arr, int n) {
    sort(arr.begin(), arr.end(),cmp);
    pair<long long, long long> prev = arr[0];
    int len = 1;
    for (int i = 1; i < n; i++) {
        if (prev.second <= arr[i].first) {
            prev = arr[i];
            len++;
        }
    }
    return len;
}

int main() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    cout << solve(arr, n);
    return 0;
}
