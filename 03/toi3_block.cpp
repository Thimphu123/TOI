#include <bits/stdc++.h>

using namespace std;

int score;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void check(vector<string>& a) {
    bool chk = true;
    while (chk) {
        chk = false;
        for (int i = 0; i < a.size() - 1; i++) for (int j = 1; j < a[0].size() - 1; j++) {
            if (a[i][j] != '#' and a[i][j] != '-' and (i + 1 < a.size() and a[i + 1][j] == '-')) {
                swap(a[i][j], a[i + 1][j]);
                chk = true;
            }
        }
    }
}

void dfs(vector<string>& a, int i, int j) {
    char b = a[i][j];
    a[i][j] = '-';
    score += 5;
    for (int di = 0; di < 4; di++) {
        if (i + dx[di] < 0 or i + dx[di] >= a.size() or j + dy[di] < 0 or j + dy[di] >= a[0].size() or b != a[i + dx[di]][j + dy[di]]) continue;
        dfs(a, i + dx[di], j + dy[di]);
    }
}

void checkk(vector<string>& a) {
    bool chk = true;
    while (chk) {
        chk = false;
        for (int i = 0; i < a.size() - 1; i++) for (int j = 1; j < a[0].size() - 1; j++) {
            if (a[i][j] != '#' and a[i][j] != '-' and ((i - 1 >= 0 and a[i - 1][j] == a[i][j]) or (i + 1 < a.size() and a[i + 1][j] == a[i][j]) or (j - 1 >= 0 and a[i][j - 1]) == a[i][j] or (j + 1 < a[0].size() and a[i][j + 1] == a[i][j]))) {
                dfs(a, i, j);
                chk = true;
            }
        }
        check(a);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int m, n, k;
    cin >> m >> n;
    vector<string> a(m, string(n, ' '));
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
    cin >> k;
    while (k--) {
        int x, y;
        char d;
        cin >> x >> y >> d;
        if (a[x][y] != '-' and a[x][y] != '#') {
            if (y - 1 >= 0 and d == 'L' and a[x][y - 1] == '-') {
                swap(a[x][y], a[x][y - 1]);
                check(a);
                checkk(a);
            } else if (y + 1 < n and d == 'R' and a[x][y + 1] == '-') {
                swap(a[x][y], a[x][y + 1]);
                check(a);
                checkk(a);
            } else score -= 5;
        } else score -= 5;
    }
    cout << score << '\n';
    for (auto i : a) {
        for (auto j : i) cout << j << ' ';
        cout << '\n';
    }
}
