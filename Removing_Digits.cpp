#include <bits/stdc++.h>
using namespace std;

int solve(int num){
    vector<int> dp(num + 1,INT_MAX);
    dp[num] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,num});
    while(!pq.empty()){
        auto temp = pq.top();pq.pop();
        int len = temp.first;
        int n = temp.second;
        if(n == 0) return len;
        if(dp[n] < len) continue;
        int myn = n;
        while(myn > 0){
            int x = myn % 10;
            if((n - x) >= 0 && dp[n - x] > len + 1){
                dp[n - x] = len + 1;
                pq.push({len + 1,n - x});
            }
            myn /= 10;
        }
    }
    return dp[num];
}
int main() {
    int n;
    cin >> n;
    cout<< solve(n);
    return 0;
}