#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, ans1 = 0, ans2 = 0;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    cin >> n >> m;
    vector<string> a(n);
    vector<vector<int>> visited(n, vector<int>(m, -1));
    vector<pair<int, int>> dest;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'X') {
                q.push({i, j});
                visited[i][j] = 0;
            }
            if (a[i][j] == 'A') {
                dest.push_back({i, j});
            }
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 or ny < 0 or nx >= n or ny >= m or visited[nx][ny] != -1 or a[nx][ny] == 'W') continue;
            visited[nx][ny] = visited[x][y] + 1;
            if (a[nx][ny] != 'X') q.push({nx, ny});
        }
    }
    for (auto [f, s] : dest) {
        if (visited[f][s] != -1) {
            ans1++;
            ans2 += 2 * visited[f][s];
        }
    }
    cout << ans1 << ' ' << ans2;
}