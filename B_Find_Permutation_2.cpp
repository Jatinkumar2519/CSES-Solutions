#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    set<int> sett;
    for(int i = 1;i <= n;i++){
        sett.insert(i);
    }
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        if(arr[i] != -1){
            if(sett.count(arr[i]) == 0){
                cout<< "No" ;
                return 0;
            }
            sett.erase(arr[i]);
        }
    }
    for(int i = 0;i < n && !sett.empty();i++){
        if(arr[i] == -1){
            arr[i] = *sett.begin();
            sett.erase(sett.begin());
        }
    }
    bool flag = true;
    for(int i = 0;i < n;i++){
        if(arr[i] == -1){
            flag = false;
            break;
        }
    }
    if(flag){
        cout<< "Yes" << endl;
        for(int i = 0;i < n;i++){
            cout<< arr[i] << ' ';
        }
    }
    else{
        cout<< "No";
    }
    return 0;
}