#include <bits/stdc++.h>
using namespace std;
long long solve(){
    int n,m;
    int mod = 1e9 + 7;
    cin >> n >> m;
    vector<long long> row(n - 1),col(m - 1);
    for(int i = 0;i < n - 1;i++){
        cin >> row[i];
    }
    for(int i = 0;i < m - 1;i++){
        cin >> col[i];
    }
    sort(row.begin(),row.end(),greater<int>());
    sort(col.begin(),col.end(),greater<int>());
    long long rowp = 1;
    long long colp = 1;
    long long count = 0;
    int i = 0;int j = 0;
    while(i < n - 1 && j < m - 1){
        if(row[i] == col[i]){
            if(rowp < colp){
                count = (count + row[i] * colp) % mod;
                rowp++;
                i++;
            }
            else{
                count = (count + col[j] * rowp) % mod;
                colp++;
                j++;
            }
        }
        else if(row[i] > col[j]){
            count = (count + row[i] * colp) % mod;
            rowp++;
            i++;
        }
        else{
            count = (count + col[j] * rowp) % mod;
            colp++;
            j++;
        }
    }
    while(i < n - 1){
        count = (count + row[i] * colp) % mod;
        rowp++;
        i++;
    }
    while(j < m - 1){
        count = (count + col[j] * rowp) % mod;
        colp++;
        j++;
    }
    return count;
}
int main() {
    int n;
    cin >> n;
    while(n--){
        cout<< solve() << endl;
    }
    return 0;
}