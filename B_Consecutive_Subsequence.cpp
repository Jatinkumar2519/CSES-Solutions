#include <bits/stdc++.h>
# define ll long long
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0;i < n;i++){
        ll num ;
        cin >> num;
        arr[i] = num;
    }
    unordered_map<ll,int> map;
    unordered_map<ll,int> indx;
    vector<int> parent(n,-1);
    int maxlen = 0;
    int end = 0;
    for(int i = 0;i < n;i++){
        if(map.count(arr[i] - 1)){
            map[arr[i]] = 1 + map[arr[i] - 1];
            parent[i] = indx[arr[i] - 1];
        }
        else{
            map[arr[i]] = 1;
        }
        indx[arr[i]] = i;
        if(maxlen < map[arr[i]]){
            maxlen = map[arr[i]];
            end = i;
        }
    }
    vector<int> path;
    while(end >= 0 && end != -1){
        path.push_back(end);
        end = parent[end];
    }
    reverse(path.begin(),path.end());
    cout<< path.size() << endl;
    for(int i : path){
        cout<< i + 1 << ' ';
    }
    return 0;
}