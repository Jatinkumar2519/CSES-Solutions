#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    int pivot = arr[0];
    int i = n - 1,j = i + 1;
    while(i > 0){
        if(arr[i] > pivot){
            j--;
            swap(arr[j],arr[i]);
        }
        i--;
    }
    swap(arr[j - 1],arr[0]);
    for(int i : arr){
        cout << i << " ";
    }
    return 0;
}