#include <bits/stdc++.h>
using namespace std;
int main() {
    int num1,num2,num3;
    cin >> num1 >> num2 >> num3;
    cout<< max({num1 * (num2 + num3),(num1 + num2) * num3,num1 + num2 + num3,num1 * num2 * num3});
    return 0;
}