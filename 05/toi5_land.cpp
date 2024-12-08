#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    double sum = DBL_MAX, pc;
    cin >> n >> m;
    vector<vector<double>> aa(n, vector<double>(m));
    vector<int> order(n * m);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> aa[i][j];
    for (int i = 0; i < n * m; i++) order[i] = i;
    do {
        pc = 0;
        vector<vector<double>> a = aa;
        for (auto i : order) {
            pc += a[i / m][i % m];
            for (int j = 0; j < 8; j++) {
                int x = (i / m) + dx[j], y = (i % m) + dy[j];
                if (x < 0 or y < 0 or x >= n or y >= m) continue;
                a[x][y] += a[i / m][i % m] * .1;
            }
        }
        sum = min(sum, pc);
    } while (next_permutation(order.begin(), order.end()));
    printf("%.2lf", sum);
}