#include <bits/stdc++.h>
using namespace std;
int solve(string& str,int target,int i,int curr){
    if(i == str.length()){
        return curr == target;
    }
    int res = 0;
    if(str[i] != '?'){
        if(str[i] == '-'){
            res += solve(str,target,i + 1,curr - 1);
        }
        else{
            res += solve(str,target,i + 1,curr + 1);
        }
    }
    else{
        res += solve(str,target,i + 1,curr + 1) + solve(str,target,i + 1,curr - 1);
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string str1,str2;
    cin >> str1 >> str2;
    int target = 0;
    for(char ch : str1){
        if(ch == '+'){
            target++;
        }
        else{
            target--;
        }
    }
    int res = solve(str2,target,0,0);
    int total = 1;
    for(char ch : str2){
        if(ch == '?'){
            total *= 2;
        }
    }
    if(res == 0){
        cout<< fixed << setprecision(12) << 0.0;
    }
    else{
        double x =  res/(total * 1.0);
        cout<< fixed << setprecision(12) << x;
    }
    return 0;
}