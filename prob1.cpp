#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define rs(n,m) resize(n,m)
#define vl vector<long long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        int  n;
        cin >> n;
        int count = 0;
        unordered_set<char> set;
        for(int i = 0;i < n;i++){
            char ch;
            cin >> ch;
            if(set.find(ch) == set.end()){
                set.insert(ch);
                count += 2;
            }
            else{
                count ++;
            }
        }
        cout<< count << endl;
    }
    return 0;
}