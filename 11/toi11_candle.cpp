#include <bits/stdc++.h>

using namespace std;

int main(){
    int m, n, ans = 0;
    scanf("%d%d", &m, &n);
    vector<string> p(m);
    for (int i = 0; i < m; i++) cin >> p[i];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (p[i][j] == '1') {
                ans++;
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty()) {
                    int f = q.front().first, s = q.front().second;
                    q.pop();
                    if (f >= p.size() or s >= p[0].size() or f < 0 or s < 0 or p[f][s] != '1') continue;
                    p[f][s] = '0';
                    q.push({f + 1, s});
                    q.push({f + 1, s + 1});
                    q.push({f, s + 1});
                    q.push({f - 1, s + 1});
                    q.push({f, s + 1});
                    q.push({f - 1, s + 1});
                    q.push({f - 1, s});
                    q.push({f - 1, s - 1});
                    q.push({f, s - 1});
                    q.push({f + 1, s - 1});
                }
            }
        }
    }
    printf("%d", ans);
}