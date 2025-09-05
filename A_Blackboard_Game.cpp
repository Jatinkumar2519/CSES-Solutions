#include <iostream>
#include <vector>
using namespace std;

string solve(int n) {
    return (n % 4 == 0) ? "Bob" : "Alice";
}

int main() {
    int t;
    cin >> t; // Number of test cases
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
