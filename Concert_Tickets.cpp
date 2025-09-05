#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<long long> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    multiset<long long> set(arr.begin(),arr.end());
    for(int i = 0;i < m;i++){
        int num;
        cin >> num;
        auto it = set.upper_bound(num);
        if(it == set.begin()){
            cout<< -1 << endl;
        }
        else{
            it--;
            cout<< *it << endl;
            set.erase(it);
        }
    }
    return 0;
}