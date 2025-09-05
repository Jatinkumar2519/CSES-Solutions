#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int total;
    cin >> total;
    vector<int> arr(7);
    for(int i = 0;i < 7;i++){
        cin >> arr[i];
    }
    int sum = 0;
    int day = 0;
    while(true){
        sum += arr[day];
        if(sum >= total){
            cout<< day + 1;
            return 0;
        }
        day = (day + 1) % 7;
    }
    return 0;
}