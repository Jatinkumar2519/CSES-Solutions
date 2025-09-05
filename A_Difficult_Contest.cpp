#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        sort(str.begin(),str.end());
        reverse(str.begin(),str.end());
        cout<< str << endl;
    } 
    return 0;
}