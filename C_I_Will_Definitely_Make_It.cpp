#include <bits/stdc++.h>
using namespace std;

string solve(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    set<int> set;
    for(int i = 0;i < n;i++){
        if(arr[i] > arr[k - 1]){
            set.insert(arr[i]);
        }
    }
    int lvl = 0;
    int curr = arr[k - 1];
    while(!set.empty()){
        int num = *set.begin() - curr;
        if(curr - lvl < num){
            return "NO";
        }
        lvl += curr - lvl + num - (curr - lvl);
        curr = *set.begin();set.erase(set.begin());
    }
    return "YES";
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