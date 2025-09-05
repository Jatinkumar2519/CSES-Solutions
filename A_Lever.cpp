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
        vector<ll> arr1(n),arr2(n);
        for(int i = 0;i < n;i++){
            cin >> arr1[i];
        }
        for(int i = 0;i < n;i++){
            cin >> arr2[i];
        }
        int count = 0;
        while(true){
            bool flag = false;
            for(int i = 0;i < n;i++){
                for(int j = 0;j < n;j++){
                    if(arr1[i] < arr2[j]){
                        flag = true;
                        arr1[i]++;
                    }
                    else if(arr1[i] > arr2[j]){
                        flag = true;
                        arr1[i]--;
                    }
                }
            }
            if(!flag) break;
            count++;
        }
        cout<< count << endl;
    }
    
    return 0;
}