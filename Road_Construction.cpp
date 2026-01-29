#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;

    int maxs = 1;

    vector<int> parent(n + 1), size(n + 1,1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    function<int(int)> find = [&](int node) -> int
    {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    };

    auto Union = [&](int node1, int node2)
    {
        int p1 = find(node1);
        int p2 = find(node2);

        if (p1 == p2)
            return false;

        if (size[p1] > size[p2])
        {
            parent[p2] = p1;
            size[p1] += size[p2];
            maxs = max(maxs,size[p1]);
        }
        else if (size[p1] < size[p2])
        {
            parent[p1] = p2;
            size[p2] += size[p1];
            maxs = max(maxs,size[p2]);
        }
        else
        {
            size[p1] += size[p2];
            maxs = max(maxs,size[p1]);
            parent[p2] = p1;
        }
        return true;
    };

    int comp = n;
    for(int i = 0;i < m;i++){
        int u,v;
        cin >> u >> v;
        if(Union(u,v)){
            comp--;
        }
        cout<< comp << ' ' << maxs << endl;
    }
    return 0;
}