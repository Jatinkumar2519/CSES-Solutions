#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string str;
    cin >> str;
    int num1 = 0,num2 = 0;
    int i = 0,n = str.length();
    while(i < n && str[i] != '-'){
        num1 = num1 * 10 + (str[i] - '0');
        i++;
    }
    i++;
    while(i < n && str[i] != '-'){
        num2 = num2 * 10 + (str[i] - '0');
        i++;
    }
    if(num2 == 8){
        num1++;
        num2 = 1;
    }
    else{
        num2++;
    }
    cout<< to_string(num1) + '-' + to_string(num2);
    return 0;
}