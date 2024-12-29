#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    long long sum = 0;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        c[i] = a[i] + b[n - i - 1];
    }
    sort(c.begin(), c.end());
    for (int i = 1; i < n; i++) {
        sum += c[i] - c[i - 1];
    }
    cout << sum;
}