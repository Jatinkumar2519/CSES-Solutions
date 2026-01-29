#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        int n ;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0;i < n;i++) cin >> arr[i];
        int sum = 0;
        for(int i = 0;i + 1 < n;i++){
            sum += abs(arr[i] - arr[i + 1]);
        }
        int minv = sum;
        for(int i = 1;i + 1 < n;i++){
            int temp = sum;
            temp -= abs(arr[i - 1] - arr[i]);
            temp -= abs(arr[i] - arr[i + 1]);
            temp += abs(arr[i - 1] - arr[i + 1]);
            minv = min(minv,temp);
        }
        cout<< min({minv,sum - abs(arr[1] - arr[0]),sum - abs(arr[n - 1] - arr[n - 2])}) << endl;
    }
    return 0;
}