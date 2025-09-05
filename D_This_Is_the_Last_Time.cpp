#include <bits/stdc++.h>
using namespace std;

int solve(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>> arr(n);
    for(int i = 0;i < n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        arr[i] = {c,a,b};
    }
    sort(arr.begin(),arr.end());
    int count = 0;
    for(int i = 0;i < n;i++){
        if(arr[i][1] <= k && k <= arr[i][2]){
            count = arr[i][0];
        }
    }
    return count;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        cout<< solve() << endl;
    }
    return 0;
}