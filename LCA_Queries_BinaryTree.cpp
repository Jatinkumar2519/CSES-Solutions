# include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> height, euler, first;
    vector<bool> visit;
    struct SegmentTree {
        vector<pair<int, int>> Tree;
        vector<int>& euler;
        vector<int>& height;

        SegmentTree(int n, vector<int>& eul, vector<int>& h) : euler(eul), height(h) {
            Tree.resize(n * 4);
            BuildTree(0, 0, n - 1);
        }

        void BuildTree(int node, int l, int r) {
            if (l == r) {
                Tree[node] = {euler[l], height[euler[l]]};
                return;
            }
            int mid = (l + r) >> 1;
            BuildTree((node << 1) + 1, l, mid);
            BuildTree((node << 1) + 2, mid + 1, r);
            if (Tree[(node << 1) + 1].second < Tree[(node << 1) + 2].second) {
                Tree[node] = Tree[(node << 1) + 1];
            } else {
                Tree[node] = Tree[(node << 1) + 2];
            }
        }

        pair<int, int> getMin(int node, int l, int r, int L, int R) {
            if (r < L || R < l) return {INT_MAX, INT_MAX};
            if (l <= L && R <= r) return Tree[node];
            int mid = (L + R) >> 1;
            auto left = getMin((node << 1) + 1, l, r, L, mid);
            auto right = getMin((node << 1) + 2, l, r, mid + 1, R);
            return (left.second < right.second) ? left : right;
        }
    };

    void DFS(int n, int node, int len) {
        visit[node] = true;
        height[node] = len;
        first[node] = euler.size();
        euler.push_back(node);

        int left = (node << 1) + 1;
        int right = (node << 1) + 2;

        if (left < n && !visit[left]) {
            DFS(n, left, len + 1);
            euler.push_back(node);
        }
        if (right < n && !visit[right]) {
            DFS(n, right, len + 1);
            euler.push_back(node);
        }
    }

    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        int nodes = (1 << n) - 1;

        height.assign(nodes, 0);
        first.assign(nodes, 0);
        visit.assign(nodes, false);
        euler.clear();
        euler.reserve(nodes * 2);

        DFS(nodes, 0, 1);

        SegmentTree code((int)euler.size(), euler, height);

        vector<int> result;
        for (auto& q : queries) {
            int u = q[0] - 1;
            int v = q[1] - 1;
            int left = first[u], right = first[v];
            if (left > right) swap(left, right);

            auto lca = code.getMin(0, left, right, 0, (int)euler.size() - 1);
            int dist = height[u] + height[v] - 2 * lca.second + 1;
            result.push_back(dist);
        }
        return result;
    }
};
