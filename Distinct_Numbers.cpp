#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count = 0;
    set<long long> set;
    for(int i = 0;i < n;i++){
        long long num;
        cin >> num;
        if(set.find(num) == set.end()){
            count++;
            set.insert(num);
        }
    }
    cout<< count;
    return 0;
}   