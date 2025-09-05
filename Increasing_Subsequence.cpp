#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct SegmentTree {
        vector<int> tree;
        SegmentTree(int n) {
            tree.resize(4 * n, 0);
        }
        void update(int node, int indx, int val, int l, int r) {
            if (l == r) {
                tree[node] = max(val, tree[node]);
                return;
            }
            if (indx < l || indx > r) return;
            int mid = (l + r) >> 1;
            update((node << 1) + 1, indx, val, l, mid);
            update((node << 1) + 2, indx, val, mid + 1, r);
            tree[node] = max(tree[(node << 1) + 1], tree[(node << 1) + 2]);
        }
        int search(int node, int l, int r, int ql, int qr) {
            if (r < ql || l > qr) return INT_MIN;
            if (ql <= l && r <= qr) return tree[node];
            int mid = (l + r) >> 1;
            return max(search((node << 1) + 1, l, mid, ql, qr),search((node << 1) + 2, mid + 1, r, ql, qr));
        }
    };

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(nums.begin(),nums.end());
        sort(sorted.begin(),sorted.end());
        sorted.erase(unique(sorted.begin(),sorted.end()),sorted.end());
        unordered_map<int, int> map;
        for (int i = 0; i < sorted.size(); i++) {
            map[sorted[i]] = i;
        }

        SegmentTree code(sorted.size());
        int maxlen = 0;

        for (int i = 0; i < n; i++) {
            int idx = map[nums[i]];
            int bestBefore = (idx == 0) ? 0 : code.search(0,  0, sorted.size() - 1,0, idx - 1);
            int currLen = 1 + bestBefore;
            code.update(0, idx, currLen, 0, sorted.size() - 1);
            maxlen = max(maxlen, currLen);
        }
        return maxlen;
    }
};
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    Solution code;
    cout<< code.lengthOfLIS(arr);
    return 0;
}