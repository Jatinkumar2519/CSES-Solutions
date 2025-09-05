#include <bits/stdc++.h>
#define ll long long
using namespace std;

static bool cmp(pair<ll,ll>& a,pair<ll,ll>& b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<pair<ll,ll>> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(),arr.end(),cmp);
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    ll count = 0;
    for(ll i = 0;i < n;i++){
        ll start = arr[i].first;
        ll end = arr[i].second;
        if(pq.empty()){
            pq.push(end);
            count++;
        }
        else if(pq.top() <= start){
            pq.pop();pq.push(end);
            count++;
        }
        else if(pq.size() < k){
            pq.push(end);
            count++;
        }
    }
    cout<< count;
    return 0;
}