#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n,m) resize(n,m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<int> arr(n);
        int sum = 0;
        int target = 0;
        for(int i = 1;i < n;i += 2){
            arr[i] = 1;
            sum++;
        }
        for(int i = 0;i < n;i += 2){
            arr[i] = -1;
            target++;
        }
        if(arr.back() == -1){
            arr[n - 2] += abs(target - sum) + 1;
        }
        else{
            arr.back() += abs(target - sum) + 1;
        }
        for(int num : arr){
            cout<< num << ' ';
        }
        cout<< endl;
    }
    
    return 0;
}