#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;

    vector<tuple<int,int,int>> arr(n);
    for(int i = 0;i < n;i++){
        int l,r;
        cin >> l >> r;
        arr[i] = make_tuple(l,r,i);
    }
    sort(arr.begin(),arr.end());

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    priority_queue<int,vector<int>,greater<>> rooms;

    vector<int> result(n);

    int id = 1;
    for(int i = 0;i < n;i++){
        auto [l,r,idx] = arr[i];

        while(!pq.empty() && pq.top().first < l){
            rooms.push(pq.top().second);
            pq.pop();
        }
        
        if(!rooms.empty()){
            result[idx] = rooms.top();
            rooms.pop();
        }
        else{
            result[idx] = id++;
        }
        pq.push({r,result[idx]});
    }

    cout<< id - 1 << endl;
    for(int i = 0;i < n;i++){
        cout<< result[i] << ' ';
    }
    return 0;
}