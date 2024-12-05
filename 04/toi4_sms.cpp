#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, s, m, h, v;
    cin >> n;
    cin >> s >> m;
    string com[10] = {"A", "A", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
    string ans;
    m--;
    if (s != 1) ans += com[s][m % com[s].size()];
    n--;
    while (n--) {
        cin >> h >> v >> m;
        s += h + v * 3;
        m--;
        if (s != 1) ans += com[s][m % com[s].size()];
        else if (!ans.empty()) {
            m++;
            while(!ans.empty() and m--) ans.pop_back();
        }
    }
    if (ans.size() > 0) cout << ans;
    else cout << "null";
}