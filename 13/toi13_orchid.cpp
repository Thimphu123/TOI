#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, a;
    cin >> n;
    vector<int> c;
    for (int i = 0; i < n; i++) {
        cin >> a;
        auto b = upper_bound(c.begin(), c.end(), a);
        if (b == c.end()) c.push_back(a);
        else *b = a;
    }
    cout << n - c.size();
}