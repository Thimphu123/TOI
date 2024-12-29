#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int x, y, n;
    cin >> x >> y >> n;
    vector<vector<pair<int, int>>> p(4, vector<pair<int, int>>(n));
    for (int i = 0; i < 4; i++) for (int j = 0; j < n; j++) cin >> p[i][j].first >> p[i][j].second;
    vector<pair<pair<int, int>, pair<int, int>>> sum;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        sum.push_back({{p[0][i].first + p[1][j].first, p[0][i].second + p[1][j].second}, {i, j}});
    }
    sort(sum.begin(), sum.end());
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        pair<int, int> tar = {x - p[2][i].first - p[3][j].first, y - p[2][i].second - p[3][j].second};
        auto iter = lower_bound(sum.begin(), sum.end(), make_pair(tar, make_pair(0, 0)));
        if (iter->first == tar) {
            cout << p[0][iter->second.first].first << ' ' << p[0][iter->second.first].second << '\n' << p[1][iter->second.second].first << ' ' << p[1][iter->second.second].second << '\n' << p[2][i].first << ' ' << p[2][i].second << '\n' << p[3][j].first << ' ' << p[3][j].second;
            return 0;
        }
    }
}