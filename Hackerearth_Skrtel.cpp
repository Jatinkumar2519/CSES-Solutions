#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> graph;

class LCA {
private:
    vector<int> tour;
    vector<int> index;
    vector<int> height;
    vector<int> segTree;
    int n;

    void dfs(int node, int parent, int level) {
        height[node] = level;
        index[node] = (int)tour.size();
        tour.push_back(node);
        for (int neighbor : graph[node]) {
            if (neighbor == parent) continue;
            dfs(neighbor, node, level + 1);
            tour.push_back(node);
        }
    }

    void buildTree(int node, int l, int r) {
        if (l == r) {
            segTree[node] = tour[l];
            return;
        }
        int mid = (l + r) / 2;
        buildTree(node * 2 + 1, l, mid);
        buildTree(node * 2 + 2, mid + 1, r);
        int leftNode = segTree[node * 2 + 1];
        int rightNode = segTree[node * 2 + 2];
        segTree[node] = (height[leftNode] < height[rightNode]) ? leftNode : rightNode;
    }

    int query(int node, int ql, int qr, int l, int r) {
        if (qr < l || ql > r) return -1;
        if (ql <= l && r <= qr) return segTree[node];
        int mid = (l + r) / 2;
        int left = query(node * 2 + 1, ql, qr, l, mid);
        int right = query(node * 2 + 2, ql, qr, mid + 1, r);
        if (left == -1) return right;
        if (right == -1) return left;
        return (height[left] < height[right]) ? left : right;
    }

public:
    LCA(int n) {
        this->n = n;
        index.assign(n + 1, 0);
        height.assign(n + 1, 0);
    }

    void preprocess(int root = 1) {
        tour.clear();
        dfs(root, -1, 0);
        int size = tour.size();
        segTree.assign(4 * size, 0);
        buildTree(0, 0, size - 1);
    }

    int findLCA(int u, int v) {
        int left = index[u];
        int right = index[v];
        if (left > right) swap(left, right);
        return query(0, left, right, 0, (int)tour.size() - 1);
    }
};
vector<int> arr;
class Calculate{
private:
    int time,n;
    vector<int> in,out;
    vector<double> diff;
public:
    Calculate(int n){
        this->n = n;
        this->time = 0;
        this->in = vector<int>(n + 1);
        this->out = vector<int>(n + 1);
        this->diff = vector<double>(n + 1,1);
    }
    void DFS(int node,int par){
        in[node] = time++;
        for(int nn : graph[node]){
            if(nn == par) continue;
            DFS(nn,node);
        }
        out[node] = time;
    }
    void init_diff_array(){
        for(int i = 1;i <= n;i++){
            diff[in[i]] *= (double)arr[i];
            diff[out[i] + 1] /= (double)arr[i];
        }
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    graph.assign(n + 1, {});
    arr = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    LCA lca(n);
    lca.preprocess(1);

    return 0;
}
