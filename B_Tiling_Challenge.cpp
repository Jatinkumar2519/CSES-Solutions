#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n, m) resize(n, m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    int dirx[] = {-1, 1, 0, 0};
    int diry[] = {0, 0, -1, 1};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '.')
            {
                bool flag = true;
                for (int d = 0; d < 4 && flag; d++)
                {
                    int ni = i + dirx[d];
                    int nj = j + diry[d];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n)
                    {
                        if (grid[ni][nj] != '.')
                        {
                            flag = false;
                        }
                    }
                    else
                    {
                        flag = false;
                    }
                }
                if (flag)
                {
                    grid[i][j] = '#';
                    for (int d = 0; d < 4; d++)
                    {
                        int ni = i + dirx[d];
                        int nj = j + diry[d];
                        grid[ni][nj] = '#';
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(grid[i][j] == '.'){
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
    return 0;
}