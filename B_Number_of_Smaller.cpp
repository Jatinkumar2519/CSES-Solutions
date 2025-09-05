#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> & arr1,vector<int>& arr2,int n,int m){
    vector<int> result(m,0);
    for(int i = 0;i < m;i++){
        int target = arr2[i];
        int left = 0;int right = n - 1;
        int indx = n;
        while(left <= right){
            int mid = (left + right)/2;
            if(arr1[mid] >= target){
                indx = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        result[i] = indx;
    }
    return result;
}
int main() {
    int n,m;
    cin >> n >> m;
    vector<int> arr1(n),arr2(m);
    for(int i = 0;i < n;i++){
        cin >> arr1[i];
    }
    for(int i = 0;i < m;i++){
        cin >> arr2[i];
    }
    vector<int> arr = solve(arr1,arr2,n,m);
    for(int i : arr){
        cout<< i << " ";
    }
    return 0;
}