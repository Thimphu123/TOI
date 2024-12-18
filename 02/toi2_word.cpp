#include <bits/stdc++.h>
using namespace std;

void findd(vector<string>& a, int m, int n, string& find) {
    int l;
    int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int di = 0; di < 8; di++) {
                for (l = 0; l < find.size(); l++) if (i + l * dx[di] < 0 or i + l * dx[di] >= m or j + l * dy[di] < 0 or j + l * dy[di] >= n or tolower(a[i + l * dx[di]][j + l * dy[di]]) != tolower(find[l])) break;
                if (l == find.size()) {
                    cout << i << ' ' << j << '\n';
                    return;
                }
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    string find;
    cin >> m >> n;
    vector<string> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    cin >> k;
    while (k--) {
        cin >> find;
        findd(a, m, n, find);
    }
}
