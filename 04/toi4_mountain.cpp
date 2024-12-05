#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int h, maxh = 0, maxw = 0;
    char cc;
    cin >> h;
    vector<pair<int, int>> a(h);
    for (int i = 0; i < h; i++) {
        int c, b;
        cin >> c >> b;
        a[i] = {c, b};
        maxh = max(maxh, b);
        maxw = max(maxw, c + b * 2 - 1);
    }
    for (int i = maxh - 1; i >= 0; i--) {
        for (int j = 1; j <= maxw; j++) {
            cc = '.';
            for (auto k : a) {
                if (k.second > i and cc != 'X') {
                    if (k.first + i == j) {
                        if (cc == '\\') cc = 'v';
                        else cc = '/';
                    } else if (k.first + i + (k.second - i) * 2 - 1 == j) {
                        if (cc == '/') cc = 'v';
                        else cc = '\\';
                    } else if (k.first + i < j and k.first + i + (k.second - i) * 2 - 1 > j) {
                        cc = 'X';
                    }
                }
            }
            cout << cc;
        }
        cout << '\n';
    }
}