#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int n)
{
    multiset<int> set;
    for (int i = 0; i < n; i++)
    {
        auto it = set.lower_bound(arr[i]);
        if(it != set.end()){
            set.erase(it);
        }
        set.insert(arr[i]);
    }
    return set.size();
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << solve(arr, n);
    return 0;
}