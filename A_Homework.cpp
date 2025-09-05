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
    int tt;
    cin >> tt;
    while(tt--){
        int n1,n2;
        string str,str1,str2;
        cin >> n1;
        cin >> str1;
        cin >> n2;
        cin >> str2;
        cin >> str;
        for(int i = 0;i < n2;i++){
            if(str[i] == 'D'){
                str1.push_back(str2[i]);
            }
            else{
                str1 = str2[i] + str1;
            }
        }
        cout<< str1 << endl;
    }
    return 0;
}