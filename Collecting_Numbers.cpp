#include <bits/stdc++.h>
using namespace std;

int solve(vector<long long> &arr, int n)
{
    multiset<long long> set;
    set.insert(arr[0]);
    for(int i = 1;i < n;i++){
        auto it = set.lower_bound(arr[i]);
        if(it == set.begin()){
            set.insert(arr[i]);
        }
        else {
            auto del = prev(it);
            set.erase(del);
            set.insert(arr[i]);
        }
    }
    return set.size();
}
int main()
{
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int res = solve(arr, n);
    cout<< res ;
    return 0;
}