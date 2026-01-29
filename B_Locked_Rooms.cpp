#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n ;
    cin >> n;
    int p = n;
    int q = 0;
    bool flag = false;
    for(int i = 0;i < n;i++){
        int num ;
        cin >> num;
        if(num){
            p = min(p,i);
            q = max(q,i);
            flag = true;
        }
    }
    if(!flag){
        cout<< 0;
        return 0;
    }
    cout<< q - p;
    return 0;
}