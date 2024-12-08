#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k, a, b, count = 0;
    cin >> n >> m >> k;
    vector<bool> check(n);
    vector<pair<int, pair<int, int>>> in;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        in.push_back({a, {1, i}});
        in.push_back({b + 1, {-1, i}});
    }
    sort(in.begin(), in.end());
    for (auto i : in) {
        if (count < m and i.second.first == 1) {
            count += 1;
            check[i.second.second] = true;
        } else if (check[i.second.second] and i.second.first == -1) {
            count -= 1;
        }
    }
    while (k--) {
        cin >> a;
        a--;
        if (check[a]) cout << "Y ";
        else cout << "N ";
    }
}