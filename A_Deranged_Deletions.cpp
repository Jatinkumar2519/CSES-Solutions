#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0;i < n;i++){
            cin >> arr[i];
        }
        if(n == 1){
            cout<<"NO"<<endl;
            continue;
        }
        multiset<int> set(arr.begin(),arr.end());
        int del = 0;
        vector<int> result;
        for(int i = 0;i < n && !set.empty();){
            if(arr[i] != *set.begin()){
                result.push_back(arr[i]);
                set.erase(set.begin());
                i++;
            }
            else{
                del++;
                if(del > 1){
                    cout<< "NO" << endl;
                }
                set.erase(set.begin());
            }
        }
        if(del == 1){
            cout<< "Yes" << endl;
            cout<< result.size() << endl;
            for(int i : result){
                cout<< i << " ";
            }
            cout<< endl;
        }
    }
    return 0;
}