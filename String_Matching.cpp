#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string p,t;
    cin >> p >> t;

    int n = p.length();
    int m = t.length();

    vector<int> lps(m,0);
    int j = 0;
    for(int i = 1;i < m;i++){
        while(j > 0 && t[j] != t[i]){
            j = lps[j - 1];
        }
        if(t[j] == t[i]) j++;
        lps[i] = j;
    }

    int count = 0;
    int i = 0;
    j = 0;
    while(i < n){
        if(p[i] == t[j]){
            i++;j++;
            if(j == m){
                j = lps[j - 1];
                count++;
            }
        }
        else{
            if(j > 0){
                j = lps[j - 1];
            }
            else{
                i++;
            }
        }
    }
    cout<< count;
    return 0;
}