#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int m, n, ans1 = 0, ans2 = 0;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n + 2));
    vector<vector<int>> visited(m, vector<int>(n + 2, 1));
    vector<vector<int>> dp(m, vector<int>(n + 2));
    for (int i = 0; i < m; i++) for (int j = 0; j < n + 2; j++) {
        if (j == 0 or j == n + 1) a[i][j] = 0;
        else cin >> a[i][j];
        if (i == 0) dp[i][j] = a[i][j];
    }
    for (int i = 1; i < m; i++) for (int j = 1; j < n + 1; j++) {
        if (i % 2) {
            dp[i][j] = dp[i - 1][j] + a[i][j];
            visited[i][j] = visited[i - 1][j];
            if (dp[i][j] == dp[i - 1][j + 1] + a[i][j]) visited[i][j] += visited[i - 1][j + 1];
            else if (dp[i][j] < dp[i - 1][j + 1] + a[i][j]) {
                visited[i][j] = visited[i - 1][j + 1];
                dp[i][j] = dp[i - 1][j + 1] + a[i][j];
            }
        } else {
            dp[i][j] = dp[i - 1][j - 1] + a[i][j];
            visited[i][j] = visited[i - 1][j - 1];
            if (dp[i][j] == dp[i - 1][j] + a[i][j]) visited[i][j] += visited[i - 1][j];
            else if (dp[i][j] < dp[i - 1][j] + a[i][j]) {
                visited[i][j] = visited[i - 1][j];
                dp[i][j] = dp[i - 1][j] + a[i][j];
            }
        }
    }
    for (int j = 1; j < n + 1; j++) {
        if (dp[m - 1][j] > ans1) {
            ans1 = dp[m - 1][j];
            ans2 = visited[m - 1][j];
        } else if (dp[m - 1][j] == ans1) {
            ans2 += visited[m - 1][j];
        }
    }
    cout << ans1 << ' ' << ans2;
}
