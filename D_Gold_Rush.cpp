#include <bits/stdc++.h>
using namespace std;
bool solve(int n,int target){
    if(n == target){
        return true;
    }
    if(n % 3 != 0 || n < target){
        return false;
    }
    return solve(n - n/3,target) || solve(n/3,target);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        int a,b;
        cin >> a >> b;
        cout<< (solve(a,b) ? "YES" : "NO") << endl;
    }
    return 0;
}