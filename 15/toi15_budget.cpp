#include <bits/stdc++.h>

using namespace std;

int find(vector<int>& par, int a) {
    if (par[a] == a) return a;
    return par[a] = find(par, par[a]);
}

int main() {
    int b, e, cnt = 0, p;
    cin >> b >> e;
    vector<int> par(b);
    for (int i = 0; i < b; i++) par[i] = i;
    vector<pair<int, pair<int, int>>> edge0;
    vector<pair<int, pair<int, int>>> edge1;
    for (int i = 0; i < e; i++) {
        int aa, bb, cc, dd;
        cin >> aa >> bb >> cc >> dd;
        if (dd) edge1.push_back({cc, {aa, bb}});
        else edge0.push_back({cc, {aa, bb}});
    }
    cin >> p;
    vector<pair<int, int>> pac(p);
    for (int i = 0; i < p; i++) cin >> pac[i].first >> pac[i].second;
    sort(edge1.begin(), edge1.end());
    for (auto [w, z] : edge1) {
        auto [f, s] = z;
        if (find(par, f) != find(par, s)) {
            par[find(par, f)] = find(par, s);
            cnt++;
        }
    }
    if (cnt == b - 1) {
        cout << 0;
        return 0;
    }
    sort(pac.begin(), pac.end());
    for (int i = p - 1; i > 0; i--) pac[i - 1].second = min(pac[i].second, pac[i - 1].second);
    for (auto& [w, z] : edge0) {
        auto [f, s] = z;
        auto itr = lower_bound(pac.begin(), pac.end(), make_pair(w, 0));
        w = itr->second;
        // cout << w << '|' << f << ' ' << s << '\n';
    }
    sort(edge0.begin(), edge0.end());
    int ans = 0;
    for (auto [w, z] : edge0) {
        auto [f, s] = z;
        if (find(par, f) != find(par, s)) {
            par[find(par, f)] = find(par, s);
            cnt++;
            ans += w;
            // cout << w << ' ';
        }
        if (cnt == b - 1) break;
    }
    cout << ans;
}