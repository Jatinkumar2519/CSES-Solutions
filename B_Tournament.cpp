#include <bits/stdc++.h>
using namespace std;

string solve() {
    int n, j, k;
    cin >> n >> j >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }
    if(n == 1) return "Yes";
    int num = arr[j - 1];
    sort(arr.begin(),arr.end());
    if(arr[0] == arr.back()) return "Yes";
    if(k == 1 && num == arr[0]) return "No";
    return "Yes";
}

int main() {
    int t; 
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}
