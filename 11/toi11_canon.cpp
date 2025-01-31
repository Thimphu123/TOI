#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, l, k;
    cin >> n >> m >> k >> l;
    vector<int> a(n);
    vector<int> pref(10000002, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]++;
        pref[a[i]]++;
    }
    for (int i = 1; i <= 10000000; i++) pref[i] += pref[i - 1];
    while (k--) {
        int ans = 0, mx = 0;
        for (int i = 0; i < m; i++) {
            int temp, b, e;
            cin >> temp;
            temp++;
            ans += pref[min(temp + l, 10000000)] - pref[max(temp - l - 1, mx)];
            mx = min(10000000, temp + l);
        }
        cout << ans << '\n';
    }
}
