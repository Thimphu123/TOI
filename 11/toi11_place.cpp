#include <bits/stdc++.h>
#define int long long

using namespace std;

int find(vector<int>& par, int a) {
    if (par[a] == a) {
        return a;
    }
    return par[a] = find(par, par[a]);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, ans = 0;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edge(m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i].first = c - 1;
        edge[i].second.first = a - 1;
        edge[i].second.second = b - 1;
    }
    vector<int> par(n);
    for (int i = 0; i < n; i++) par[i] = i;
    sort(edge.begin(), edge.end(), greater<>());
    for (auto t : edge) {
        if (find(par, t.second.first) != find(par, t.second.second)) {
            par[find(par, t.second.first)] = find(par, t.second.second);
            ans += t.first;
        }
    }
    cout << ans;
}