#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string m, n;
    int k;
    cin >> m >> n >> k;
    while (k--) {
        string w;
        cin >> w;
        vector<vector<bool>> dp(m.size() + 1, vector<bool>(n.size() + 1));
        dp[0][0] = true;
        for (int i = 0; i <= m.size(); i++) {
            for (int j = 0; j <= n.size(); j++) {
                if (i > 0 and dp[i - 1][j] and w[i + j - 1] == m[i - 1]) dp[i][j] = true;
                if (j > 0 and dp[i][j - 1] and w[i + j - 1] == n[j - 1]) dp[i][j] = true;
            }
        }
        if (dp[m.size()][n.size()]) cout << "Yes\n";
        else cout << "No\n";
    }
}
