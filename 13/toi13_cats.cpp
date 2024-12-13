#include <bits/stdc++.h>

using namespace std;

int n;

bool valid(int mid, const vector<unsigned int>& all) {
    queue<unsigned int> q;
    for (int i = 0; i < n; i++) {
        if (all[i] > mid) {
            if (q.empty()) {
                q.push(all[i]);
            } else {
                if (all[i] != q.front()) {
                    return false;
                }
                q.pop();
            }
        }
    }
    return true;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    unsigned int l = 1, r = 1;
    bool found = false;
    vector<unsigned int> all(n);
    for (int i = 0; i < n; i++) {
        cin >> all[i];
        r = max(r, all[i]);
    }
    while (l < r) {
        unsigned int mid = (l + r) / 2;
        if (valid(mid, all)) r = mid;
        else {
            l = mid + 1;
            found = true;
        }
    }
    if (found) cout << l;
    else cout << 0;
}