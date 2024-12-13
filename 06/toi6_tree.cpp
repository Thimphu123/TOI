#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 5;
    while (t--) {
        int n, a, b;
        bool ans = true;
        cin >> n;
        vector<vector<int>> adj1(n);
        vector<vector<int>> adj2(n);
        for (int i = 0; i < n - 1; i++) {
            cin >> a >> b;
            a--;
            b--;
            adj1[a].push_back(b);
            adj1[b].push_back(a);
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> a >> b;
            a--;
            b--;
            adj2[a].push_back(b);
            adj2[b].push_back(a);
        }
        for (int i = 0; i < adj1.size(); i++) {
            int temp1 = 0, temp2 = 0;
            for (auto j : adj1[i]) temp1 += j;
            for (auto j : adj2[i]) temp2 += j;
            if (temp1 != temp2) ans = false;
        }
        if (ans) cout << 'Y';
        else cout << 'N';
    }
}