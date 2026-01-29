#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,k;
    cin >> n >> k;

    int a,b,c,d;
    cin >> a >> b >> c >> d;

    vector<int> arr(n);
    arr[0] = a;
    for(int i = 1;i < n;i++){
        arr[i] = (int)(b * 1LL * arr[i - 1] + c) % d;
    }

    vector<int> bits(32,0);

    auto getNum = [&](){
        int num = 0;
        for(int b = 0;b < 32;b++){
            if(bits[b]){
                num |= (1 << b);
            }
        }
        return num;
    };

    for(int i = 0;i < k;i++){
        for(int b = 0;b < 32;b++){
            if(arr[i] & (1 << b)){
                bits[b]++;
            }
        }
    }

    int res = getNum();

    for(int i = k;i < n;i++){
        for(int b = 0;b < 32;b++){
            if(arr[i - k] & (1 << b)){
                bits[b]--;
            }
        }
        for(int b = 0;b < 32;b++){
            if(arr[i] & (1 << b)){
                bits[b]++;
            }
        }
        res ^= getNum();
    }
    
    cout << res;
    return 0;
}