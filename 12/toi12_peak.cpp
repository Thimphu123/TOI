#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k, a;
    cin >> n >> k;
    vector<int> top;
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    if (b[0] > b[1]) top.push_back(b[0]);
    for (int i = 1; i < n - 1; i++) if (b[i] > b[i - 1] and b[i] > b[i + 1]) top.push_back(b[i]);
    if (b[n - 1] > b[n - 2]) top.push_back(b[n - 1]);
    sort(top.begin(), top.end());
    top.resize(unique(top.begin(), top.end()) - top.begin());
    if (top.empty()) {
        cout << -1;
        return 0;
    }
    if (top.size() < k) {
        for (auto i = top.begin(); i != top.end(); i++) {
            cout << *i << '\n';
        }
    } else {
        auto iter = top.end();
        for (int j = 0; iter != top.begin() and j < k; j++) {
            iter--;
            cout << *iter << '\n';
        }
    }
}