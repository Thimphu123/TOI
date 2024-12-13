#include <bits/stdc++.h>

using namespace std;

int m, n, t;
map<pair<int, int>, vector<int>> memo;

void recur(int i, int j, vector<int> ans, const vector<vector<int>>& a) {
    if (j  == t - 1) {
        for (auto k : ans) cout << k << '\n';
        return;
    }
    if (i - 1 >= 0 and !a[j + 1][i - 1]) {
        if (memo.find({i - 1, j + 1}) != memo.end()) recur(i - 1, j + 1, memo[{i - 1, j + 1}], a);
        else {
            vector<int> nans = ans;
            nans.push_back(1);
            memo[{i - 1, j + 1}] = nans;
            recur(i - 1, j + 1, nans, a);
        }
    }
    if (i + 1 < m and !a[j + 1][i + 1]) {
        if (memo.find({i + 1, j + 1}) != memo.end()) recur(i + 1, j + 1, memo[{i + 1, j + 1}], a);
        else {
            vector<int> nans = ans;
            nans.push_back(2);
            recur(i + 1, j + 1, nans, a);
        }
    }
    if (!a[j + 1][i]) {
        if (memo.find({i, j + 1}) != memo.end()) recur(i, j + 1, memo[{i, j + 1}], a);
        else {
            vector<int> nans = ans;
            nans.push_back(3);
            recur(i, j + 1, nans, a);
        }
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> m >> n >> t;
    vector<vector<int>> a(t, vector<int>(m));
    for (int i = 0; i < t; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    vector<int> ans;
    recur(n - 1, -1, ans, a);
}