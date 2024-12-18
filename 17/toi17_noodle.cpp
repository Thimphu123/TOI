#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, k;

bool check(vector<int>& a, int mid) {
    int sum = 0, cnt = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        pq.push(a[i]);
        if (pq.size() > k) {
            sum -= pq.top();
            pq.pop();
        }
        if (pq.size() == k and sum >= mid) {
            cnt++;
            sum = 0;
            while (!pq.empty()) pq.pop();
        }
    }
    if (cnt < m) return false;
    else return true;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int l = 0, r = LLONG_MAX;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(a, mid)) l = mid + 1;
        else r = mid - 1;
    }
    cout << r;
}
