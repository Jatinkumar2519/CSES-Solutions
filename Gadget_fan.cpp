#include <bits/stdc++.h>
using namespace std;

long long solve(){
    long long n,k;
    cin >> n >> k;
    long long count = 0;
    for(long long a = 1;a + a <= k;a++){
        long long b = k - a;
        if(a <= b)
            count += (b - a + 1);
    }
    return count;
}
int main() {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cout<< solve() << endl;
    }
    return 0;
}