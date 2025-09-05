#include <bits/stdc++.h>
using namespace std;
bool solve(long long num,long long target,vector<int>& curr){
    if(num == target){
        return true;
    }
    if(num * 2 <= target){
        curr.push_back(num * 2);
        if(solve(num * 2,target,curr)) return true;
        curr.pop_back();
    }
    if(num <= (target - 1) / 10){
        curr.push_back(num * 10 + 1);
        if(solve(num * 10 + 1,target,curr)) return true;
        curr.pop_back();
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long long target,n;
    cin >> target >> n;
    vector<int> curr  ;
    curr.push_back(target);
    bool res = solve(target,n,curr);
    if(!res){
        cout<< "NO";
    }
    else{
        cout<< "YES" << endl;
        cout<< curr.size() << endl;
        for(int i : curr){
            cout<< i << ' ';
        }
    }
    return 0;
}