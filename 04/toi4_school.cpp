#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};

void water(vector<string>& a, vector<vector<bool>>& visited, int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    while (!q.empty()) {
        int f = q.front().first, s = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = f + dx[i], ny = s + dy[i];
            if (nx < 0 or nx >= a.size() or ny < 0 or ny >= a[0].size() or visited[nx][ny]) continue;
            if (a[nx][ny] == 'P') {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int w, l, ans1 = 0, ans2 = INT_MAX;
    cin >> w >> l;
    vector<string> a(l);
    queue<pair<int, int>> q;
    for (int i = 0; i < l; i++) cin >> a[i];
    vector<vector<int>> prftree(l + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= l; i++) for (int j = 1; j <= w; j++) prftree[i][j] = (a[i - 1][j - 1] == 'T') + prftree[i][j - 1] + prftree[i - 1][j] - prftree[i - 1][j - 1];
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < w; j++) {
            for (int k = 1; i + k <= l and j + k <= w; k++) {
                if (prftree[i + k][j + k] - prftree[i][j + k] - prftree[i + k][j] + prftree[i][j] != 0) continue;
                if (k >= ans1) {
                    int waterr = 0;
                    vector<vector<bool>> visited(l, vector<bool>(w));
                    for (int l = i; l < k + i; l++) {
                        for (int m = j; m < k + j; m++) {
                            if (a[l][m] == 'P' and !visited[l][m]) {
                                water(a, visited, l, m);
                                waterr++;
                            }
                        }
                    }
                    if (k == ans1) ans2 = min(ans2, waterr);
                    else ans2 = waterr;
                    ans1 = k;
                }
            }
        }
    }
    cout << ans1 * ans1 << ' ';
    if (ans2 == INT_MAX) cout << 0;
    else cout << ans2;
}