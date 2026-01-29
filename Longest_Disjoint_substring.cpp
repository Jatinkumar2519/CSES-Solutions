#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    int k;
    cin >> str >> k;
    int n = str.length();
    function<bool(int)> check = [&](int mid) -> bool
    {
        unordered_map<string, vector<int>> map;

        for (int i = 0; i + mid <= n; i++)
        {
            string s = str.substr(i, mid);
            map[s].push_back(i);
        }

        for (auto &[_, arr] : map)
        {
            sort(arr.begin(), arr.end()); 
            int count = 1;
            int prev = arr[0];
            for (int i = 1; i < arr.size(); i++)
            {
                if (arr[i] - prev >= mid)
                {
                    prev = arr[i];
                    count++;
                }
            }
            if (count >= k)
                return true;
        }
        return false;
    };
    int res = 0;
    int left = 1;
    int right = n / k;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (check(mid))
        {
            res = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << res;
    return 0;
}