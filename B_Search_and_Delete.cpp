#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n,m) resize(n,m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    multiset<int> set;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        int num;
        cin >> num;
        set.insert(num);
        arr[i] = num;
    }
    for(int i = 0;i < m;i++){
        int num;
        cin >> num;
        if(set.count(num)){
            set.erase(set.find(num));
        }
    }
    for(int num : arr){
        if(set.count(num)){
            cout<< num << " ";
            set.erase(set.find(num));
        }
    }
    return 0;
}