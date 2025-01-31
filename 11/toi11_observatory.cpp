#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int m, n, k;
    cin >> n >> m >> k;
    vector<vector<int>> prefl(n + 1, vector<int>(m + 2, 0));
    vector<vector<int>> prefr(n + 1, vector<int>(m + 2, 0));
    vector<vector<int>> pref(n + 2, vector<int>(m + 2, 0));
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        pref[i][j] = pref[i - 1][j] + pref[i][j - 1] + a[i - 1][j - 1] - pref[i - 1][j - 1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= m + 1; j++) {
            prefl[i][j] = prefl[i - 1][j - 1] + prefl[i][j - 1] + a[i - 1][j - 2] - prefl[i - 1][j - 2];
        }
        for (int j = m - 1; j >= 0; j--) {
            prefr[i][j] = prefr[i - 1][j + 1] + prefr[i][j + 1] + a[i - 1][j] - prefr[i - 1][j + 2];
        }
    }
    int mx = INT_MIN;
    for (int i = k; i <= n; i++) for (int j = k; j <= m; j++) {
        mx = max(mx, prefl[i][j + 1] - prefl[i - k][j - k + 1] - (pref[i][j - k] - pref[i - k][j - k]));
        mx = max(mx, prefr[i][j - k] - prefr[i - k][j] - (pref[i][m] - pref[i][j] - pref[i - k][m] + pref[i - k][j]));
    }
    cout << mx;
}
