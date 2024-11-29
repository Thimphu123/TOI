#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    string c, d, e;
    cin >> c >> d >> e;
    for (int i = 0; i < a + b - 1; i++) {
        for (int j = min(i, a - 1); j > max(i - b, -1); j--) {
            // cout << max(j - i + b - 1, 0) << '|' << j << ' ' << i << ' ';
            if (c[j] < d[j]) {
                if (e[max(j - i + b - 1, 0)] < c[j]) {
                    e[max(j - i + b - 1, 0)] = c[j];
                } else if (e[max(j - i + b - 1, 0)] > d[j]) {
                    e[max(j - i + b - 1, 0)] = d[j];
                }
            } else if (c[j] > d[j]) {
                if (e[max(j - i + b - 1, 0)] > c[j]) {
                    e[max(j - i + b - 1, 0)] = c[j];
                } else if (e[max(j - i + b - 1, 0)] < d[j]) {
                    e[max(j - i + b - 1, 0)] = d[j];
                }
            } else {
                e[max(j - i + b - 1, 0)] = c[j];
            }
        }
    }
    cout << e;
}