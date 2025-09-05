#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

vector<int> buildLPS(const string &pat) {
    int m = pat.size();
    vector<int> lps(m, 0);
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && pat[i] != pat[j]) {
            j = lps[j - 1];
        }
        if (pat[i] == pat[j]) j++;
        lps[i] = j;
    }
    return lps;
}

void KMPsearch(const string &text, const string &pat,
               vector<bool> &check) {
    int n = text.size(), m = pat.size();
    vector<int> lps = buildLPS(pat);
    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pat[j]) {
            i++; j++;
            if (j == m) {
                check[i - m] = true; 
                j = lps[j - 1];
            }
        } else {
            if (j == 0) i++;
            else j = lps[j - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    int x;
    cin >> x;
    vector<string> words(x);
    for (int i = 0; i < x; i++) cin >> words[i];

    int n = str.size();

    vector<vector<bool>> check(x, vector<bool>(n, false));
    for (int j = 0; j < x; j++) {
        KMPsearch(str, words[j], check[j]);
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < x; j++) {
            int len = words[j].size();
            if (i >= len && check[j][i - len]) {
                dp[i] = (dp[i] + dp[i - len]) % MOD;
            }
        }
    }

    cout << dp[n] << "\n";
    return 0;
}
