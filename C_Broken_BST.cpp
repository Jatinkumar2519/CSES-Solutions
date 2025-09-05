#include <bits/stdc++.h>
using namespace std;
bool solve(vector<vector<long long>>& arr, long long node, long long target) {
    if (node == -1) return false;

    if (arr[node][0] == target) return true;

    if (target < arr[node][0]) {
        return solve(arr, arr[node][1], target);
    } else {
        return solve(arr, arr[node][2], target);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    long long n;
    cin >> n;

    vector<vector<long long>> arr(n);
    vector<bool> isChild(n, false);

    for (long long i = 0; i < n; ++i) {
        long long v, l, r;
        cin >> v >> l >> r;
        l = (l == -1 ? -1 : l - 1);
        r = (r == -1 ? -1 : r - 1);
        arr[i] = {v, l, r};

        if (l != -1) isChild[l] = true;
        if (r != -1) isChild[r] = true;
    }
    long long root = -1;
    for (long long i = 0; i < n; ++i) {
        if (!isChild[i]) {
            root = i;
            break;
        }
    }

    long long failCount = 0;

    for (long long i = 0; i < n; ++i) {
        bool result = solve(arr, root, arr[i][0]);
        if (!result) failCount++;
    }

    cout << failCount << '\n';
    return 0;
}
