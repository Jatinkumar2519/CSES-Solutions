#include <iostream>
using namespace std;

int solve(){
    int num;
    cin >> num;
    int count = 0;
    if(num >= 100){
        count += num / 100;
        num = num % 100;
    }
    if(num >= 20){
        count += num / 20;
        num %= 20;
    }
    if(num >= 10){
        count += num / 10;
        num %= 10;
    }
    if(num >= 5){
        count += num / 5;
        num %= 5;
    }
    if(num >= 1){
        count += num / 1;
        num %= 1;
    }
    return count;
}
int main() {
    cout<< solve()<<endl;
    return 0;
}