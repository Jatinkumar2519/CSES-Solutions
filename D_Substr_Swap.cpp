#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n,m) resize(n,m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    string str1,str2;
    cin >> str1 >> str2;
    vector<int> arr(n + 1,0);
    for(int i = 0;i < m;i++){
        int x,y;
        cin >> x >> y;
        x--;
        arr[x] ++;
        arr[y]--;
    }
    for(int i = 1;i < n;i++){
        arr[i] += arr[i - 1];
    }
    for(int i = 0;i < n;i++){
        if(arr[i] % 2 != 0){
            str1[i] = str2[i];
        }
    }
    cout<< str1;
    return 0;
}