#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> m >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) {
        if (i > 0) {
            if (dp[i - 1][j] % m + a[i - 1] > m) dp[i][j] = min(dp[i][j], (dp[i - 1][j] / m + 1) * m + a[i - 1]);
            else dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i - 1]);
        }
        if (j > 0) {
            if (dp[i][j - 1] % m + b[j - 1] > m) dp[i][j] = min(dp[i][j], (dp[i][j - 1] / m + 1) * m + b[j - 1]);
            else dp[i][j] = min(dp[i][j], dp[i][j - 1] + b[j - 1]);
        }
    }
    if (dp[n][n] % m == 0) {
        cout << dp[n][n] / m << '\n' << m;
    } else {
        cout << dp[n][n] / m  + 1 << '\n' << dp[n][n] % m;
    }
}