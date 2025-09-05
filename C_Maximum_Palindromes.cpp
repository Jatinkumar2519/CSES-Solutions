#include <bits/stdc++.h>
using namespace std;
int main() {
    string str;
    cin >> str;
    int n;
    cin >> n;
    for(int _ = 0;_ < n;_++){
        int i,j;
        cin >> i >> j;
        map<char,int> map;
        for(int k = i - 1;k < j;k++){
            map[str[k]]++;
        }
        int count1 = 0,count2 = 0;
        for(auto temp : map){
            if(temp.second % 2 == 1){
                count1 = max(count1,temp.second);
            }
            else{
                count2 = max(count2,temp.second);
            }
        }
        
    }
    return 0;
}