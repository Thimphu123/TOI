#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k, start = 0, stop = 0, ans = 0;
    cin >> n >> k;
    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];
    while (stop < n) {
        if (k >= d[stop + 1] - d[start]) {
            stop++;
        } else {
            start++;
        }
        ans = max(stop - start, ans);
    }
    cout << ans;
}