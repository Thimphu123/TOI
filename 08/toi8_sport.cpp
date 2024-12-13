#include <bits/stdc++.h>

using namespace std;

int k, a, b;

void recur(int aa, int bb, string ans) {
    if (aa == k or bb == k) {
        for (auto i : ans) cout << i << ' ';
        cout << '\n';
        return;
    }
    recur(aa + 1, bb, ans + 'W');
    recur(aa, bb + 1, ans + 'L');
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> k >> a >> b;
    recur(a, b, "");
}