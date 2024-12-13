#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k, a, mx = 0;
    cin >> m >> n >> k;
    vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
        cin >> a;
        pref[i][j] = a + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
    }
    for (int i = k; i <= m; i++) for (int j = k; j <= n; j++) mx = max(mx, pref[i][j] - pref[i - k][j] - pref[i][j - k] + pref[i - k][j - k]);
    cout << mx;
}