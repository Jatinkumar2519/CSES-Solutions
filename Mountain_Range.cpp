#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<long long> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    stack<int> s;
    int maxlen = 0;
    for(int i = n - 1;i >= 0;i--){
        while(!s.empty() && arr[s.top()] < arr[i]) s.pop();
        if(s.empty()) maxlen = max(maxlen ,n - i);
        else maxlen = max(maxlen,i - s.top() + 1);
        s.push(i);
    }
    cout<< maxlen;
    return 0;
}