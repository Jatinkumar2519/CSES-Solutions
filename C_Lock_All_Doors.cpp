#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    int indx = (m - 2);
    int left = indx;
    int count = 0;
    while(left >= 0){
        if(arr[left] == 1){
            count++;
        }
        left--;
    }
    left++;
    while(left < indx && arr[left] == 1){
        count--;
        left++;
    }
    count += indx - left + 1;
    indx = min(n,m - 1);
    int right = indx;
    while(right < n){
        if(arr[right] == 1){
            count++;
        }
        right++;
    }
    right--;
    while(right > indx && arr[right] == 1){
        count--;
        right--;
    }
    count += right - indx + 1;
    cout<< count;
    return 0;
}