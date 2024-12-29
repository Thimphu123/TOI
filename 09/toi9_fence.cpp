#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, t, a, b, ans = 0;
    cin >> n >> m;
    vector<vector<bool>> garden(n, vector<bool>(m));
    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
    cin >> t;
    while (t--) {
        cin >> a >> b;
        garden[a][b] = true;
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        pref[i][j] = garden[i - 1][j - 1] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        for (int k = 1; i + k - 1 <= n and j + k - 1 <= m; k++) {
            int x1 = i, y1 = j;
            int x2 = i + k - 1, y2 = j + k - 1;
            if ((pref[x1][y2] - pref[x1 - 1][y2] - pref[x1][y1 - 1] + pref[x1 - 1][y1 - 1] == 0) and (pref[x2][y2] - pref[x2 - 1][y2] - pref[x2][y1 - 1] + pref[x2 - 1][y1 - 1] == 0) and (pref[x2][y1] - pref[x1 - 1][y1] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1] == 0) and (pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y2 - 1] + pref[x1 - 1][y2 - 1] == 0)) {
                ans = max(ans, k);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    solve();
}