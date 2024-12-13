#include <bits/stdc++.h>

using namespace std;

int k, n;
int a[500000];
int dp[500000];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int b;
    cin >> n >> k;
    multiset<int> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    dp[n - 1] = a[n - 1];
    q.insert(dp[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        if (i + k + 1 < n) {
            q.erase(q.find(dp[i + k + 1]));
        }
        dp[i] = a[i] + *q.begin();
        q.insert(dp[i]);
    }
    cout << dp[0];
}