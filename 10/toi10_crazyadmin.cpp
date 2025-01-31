#include <bits/stdc++.h>

using namespace std;

int m;

bool chk(vector<int>& a, int mid) {
    int temp = 0, cnt = 1;
    for (int i = 0; i < a.size(); i++) {
        if (temp + a[i] > mid) {
            temp = a[i];
            cnt++;
        } else temp += a[i];
    }
    return cnt <= m;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int o, l = 0, r = 0;
    cin >> m >> o;
    vector<int> a(o);
    for (int i = 0; i < o; i++) {
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i];
    }
    while (l < r) {
        int mid = (l + r) / 2;
        if (chk(a, mid)) r = mid;
        else l = mid + 1;
    }
    cout << l;
}
