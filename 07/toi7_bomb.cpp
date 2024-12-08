#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int>& a, pair<int, int>& b) {
    if (a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, a, b;
    cin >> n;
    vector<pair<int, int>> in(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        in[i] = {a, b};
    }
    sort(in.begin(), in.end(), comp);
    int maxx = -1;
    for (auto [f, s] : in) {
        if (s >= maxx) {
            maxx = s;
            cout << f << ' ' << s << '\n';
        }
    }
}