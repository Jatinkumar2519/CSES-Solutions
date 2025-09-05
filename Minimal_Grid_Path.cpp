#include <bits/stdc++.h>
using namespace std;

string solve(vector<vector<char>>& grid, int n)
{
    vector<vector<string>> dp(n, vector<string>(n, string(3000001, 'z')));
    dp[0][0] = string(1, grid[0][0]);

    int dirx[] = {1, 0};
    int diry[] = {0, 1};
    priority_queue<tuple<string, int, int>, vector<tuple<string, int, int>>, greater<tuple<string, int, int>>> pq;
    pq.push(make_tuple(dp[0][0], 0, 0));

    while (!pq.empty()) {
        string str;
        int x, y;
        tie(str, x, y) = pq.top();
        pq.pop();

        if (x == n - 1 && y == n - 1) return str;
        if (dp[x][y] < str) continue;

        for (int d = 0; d < 2; ++d) {
            int nx = x + dirx[d];
            int ny = y + diry[d];
            if (nx < n && ny < n) {
                string newstr = str + grid[nx][ny];
                if (dp[nx][ny] > newstr) {
                    dp[nx][ny] = newstr;
                    pq.push(make_tuple(newstr, nx, ny));
                }
            }
        }
    }
    return " ";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    cout << solve(grid, n);
    return 0;
}
