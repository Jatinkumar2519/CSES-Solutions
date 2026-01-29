#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,k;
    cin >> n >> k;

    vector<pair<int,int>> arr(n);
    for(int i = 0;i < n;i++){
        int l,r;
        cin >> l >> r;
        arr[i] = make_pair(l,r);
    }
    sort(arr.begin(),arr.end(),[](auto& a,auto& b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        return a.second < b.second;
    });

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    priority_queue<int,vector<int>,greater<>> free;

    for(int i = 0;i < k;i++){
        free.push(i);
    }

    int count = 0;
    for(int i = 0;i < n;i++){
        auto [l,r] = arr[i];

        while(!pq.empty() && pq.top().first < l){
            free.push(pq.top().second);
            pq.pop();
        }
        
        if(!free.empty()){
            pq.push({r,free.top()});
            count++;free.pop();
        }
    }

    cout<< count << endl;
    return 0;
}