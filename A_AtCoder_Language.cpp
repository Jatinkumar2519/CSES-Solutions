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
    string str;
    cin >> str;
    if(str == "red") cout<< "SSS";
    else if(str == "blue") cout<< "FFF";
    else if(str == "green") cout<< "MMM";
    else cout<< "Unknown";
    return 0;
}