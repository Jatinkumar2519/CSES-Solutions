#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> grid(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        grid[a].push_back(b);
        grid[b].push_back(a);
    }

    int dp[n + 1][2];

    function<int(int, int, int)> solve = [&](int node, int par, int status) -> int
    {
        if (dp[node][status] != -1) return dp[node][status];

        int maxv = 0;
        if (status)
        {
            int sum = 0;
            unordered_map<int,int> map;
            for (int &nn : grid[node])
            {
                if (nn == par) continue;

                map[nn] = solve(nn,node,1);
                sum += map[nn];
            }
            for (int &nn : grid[node])
            {
                if (nn == par) continue;
                maxv = max(maxv,sum - map[nn] + 1 + solve(nn,node,0));
            }
        }
        else{
            int val = 0;
            for (int &nn : grid[node])
            {
                if (nn == par) continue;
                val += solve(nn,node,1);
            }
            maxv = max(maxv,val);
        }
        return dp[node][status] = maxv;
    };

    memset(dp,-1,sizeof(dp));
    cout<< max(solve(1,-1,0),solve(1,-1,1));

    return 0;
}