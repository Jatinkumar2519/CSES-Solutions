#include <bits/stdc++.h>
using namespace std;

int solve(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    int i = 0;
    int count = 0;
    while(i < n){
        if(arr[i] == 1){
            i++;
        }
        else{
            int j = i;
            while(j < i + k && j < n && arr[j] == 0){
                j++;
            }
            if(j == i + k){
                count++;
            }
            i = j + 1;
        }
    }
    return count;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        cout<< solve() << endl;
    }
    return 0;
}