#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n,m) resize(n,m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

struct State {
    long long sum;
    int idx;
    bool operator>(const State& other) const {
        return sum > other.sum;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    priority_queue<State, vector<State>, greater<State>> pq;
    set<pair<long long, int>> vis;

    pq.push({0, 0});
    vis.insert({0, 0});

    for (int cnt = 0; cnt < k; cnt++) {
        auto cur = pq.top();
        pq.pop();
        cout << cur.sum << " ";

        if (cur.idx < n) {
            // include arr[idx]
            auto s1 = make_pair(cur.sum + arr[cur.idx], cur.idx + 1);
            if (!vis.count(s1)) {
                pq.push({s1.first, s1.second});
                vis.insert(s1);
            }
            // skip arr[idx]
            auto s2 = make_pair(cur.sum, cur.idx + 1);
            if (!vis.count(s2)) {
                pq.push({s2.first, s2.second});
                vis.insert(s2);
            }
        }
    }
}
