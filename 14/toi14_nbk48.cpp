#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q, a;
    cin >> n >> q;
    vector<ll> price(n);
    cin >> price[0];
    for (int i = 1; i < n; i++) {
        cin >> price[i];
        price[i] += price[i - 1];
    }
    for (int i = n - 2; i >= 0; i--) price[i] = min(price[i], price[i + 1]);
    while (q--) {
        cin >> a;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (price[mid] <= a) l = mid + 1;
            else r = mid - 1;
        }
        cout << r + 1 << '\n';
    }
}