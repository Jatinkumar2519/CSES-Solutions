#include <bits/stdc++.h>
using namespace std;
vector<long long> dp;
int upper_bound(vector<vector<long long>>& events,int target){
    int left = 0;
    int right = events.size();
    while(left < right){
        int mid = (left + right)/2;
        if(events[mid][0] <= target){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    return left;
}
long long solve(vector<vector<long long>>& events,int i){
    if(i == events.size()){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    int nextindx = upper_bound(events,events[i][1]);
    return dp[i] = max(solve(events,i + 1),events[i][2] + solve(events,nextindx));
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    dp.resize(n,-1);
    vector<vector<long long>> events(n);
    for(int i = 0;i < n;i++){
        long long a,b,c;
        cin >> a >> b >> c;
        events[i] = {a,b,c};
    }
    sort(events.begin(),events.end());
    cout<< solve(events,0);
    return 0;
}