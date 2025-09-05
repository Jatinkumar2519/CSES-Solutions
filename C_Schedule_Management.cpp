#include <bits/stdc++.h>
using namespace std;
bool check(vector<int>& arr,int n,int time){
    
}
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> arr(m);
    for(int i = 0;i < m;i++){
        cin >> arr[i];
    }
    int left = 1;
    int right = 2 * m;
    int time = 1;
    while(left <= right){
        int mid = (left + right)/2;
        if(check(arr,n,mid)){
            time = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    cout<< time << endl;
}
int main() {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        solve();
    }
    return 0;
}