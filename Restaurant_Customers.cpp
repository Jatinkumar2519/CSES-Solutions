#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<long long> time;
    vector<vector<long long>> events(n);
    for(int i = 0;i < n;i++){
        long long a ,b;
        cin >> a >> b;
        events[i] = {a,b};
        time.push_back(a);
        time.push_back(b);
    }
    sort(time.begin(),time.end());
    unordered_map<long long,int> map;
    for(int i = 0;i < time.size();i++){
        if(map.find(time[i]) == map.end()){
            map[time[i]] = i;
        }
    }
    int nn = map.size();
    vector<int> dp(nn + 1,0);
    for(auto& temp : events){
        int a = map[temp[0]];
        int b = map[temp[1]];
        dp[a] ++;
        dp[b + 1] --;
    }
    long long sum = 0;
    long long maxsum = 0;
    for(int i = 0;i < nn;i++){
        sum += dp[i];
        maxsum = max(maxsum,sum);
    }
    cout<< maxsum;
    return 0;
}