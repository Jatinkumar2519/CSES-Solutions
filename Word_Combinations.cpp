#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string str;
    cin >> str;

    int n ;
    cin >> n;

    vector<string> words(n);
    for(int i = 0;i < n;i++){
        cin >> words[i];
    }

    int m = str.length();
    vector<int> dp(m + 1,0);
    dp[0] = 1;

    for(int i = 1;i <= m;i++){
        for(auto& word : words){
            int len = word.length();
            if(i >= len && str.substr(i - len,len) == word){
                dp[i] = (dp[i] + dp[i - len]) % MOD;
            }
        }
    }
    cout<< dp[m];
    return 0;
}