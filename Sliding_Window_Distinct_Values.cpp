#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    map<int,int> map;
    for(int i = 0;i < k;i++){
        map[arr[i]]++;
    }
    cout<< map.size() << ' ';
    for(int i = k;i < n;i++){
        if(--map[arr[i - k]] == 0){
            map.erase(arr[i - k]);
        }
        map[arr[i]]++;
        cout<< map.size() << ' ';
    }
    return 0;
}