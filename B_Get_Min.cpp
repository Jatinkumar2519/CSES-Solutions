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
    int n;
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i = 0;i < n;i++){
        int x,y;
        cin >> x;
        if(x == 1){
            cin >> y;
            pq.push(y);
        }
        else{
            cout<< pq.top() << endl;pq.pop();
        }
    }
    return 0;
}