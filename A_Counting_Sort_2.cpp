#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int maxele = 0;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        maxele = max(maxele,arr[i]);
    }
    vector<int> result(maxele + 1,0);
    for(int i = 0;i < n;i++){
        result[arr[i]] ++;
    }
    for(int i = 0;i <= maxele;i++){
        while(result[i] > 0){
            cout<< i << " ";
            result[i]--;
        }
    }
    return 0;
}