#include <bits/stdc++.h>

using namespace std;

void print(const vector<int>& par, const vector<vector<pair<int, double>>>& adjl, int a) {
    if (par[a] == a) {
        return;
    }
    print(par, adjl, par[a]);
    for (auto i : adjl[par[a]]) {
        if (i.first == a) {
            if (par[a] == 0) cout << 'X';
            else cout << (char)(par[a] + 'a' - 1);
            cout << ' ';
            if (a == 27) cout << 'Y';
            else cout << (char)(a + 'a' - 1);
            cout << ' ';
            cout << fixed << setprecision(1) << i.second;
            cout << '\n';
        }
    }
}

int find(const vector<int>& par, int a) {
    if (par[a] == a) {
        return a;
    }
    return find(par, par[a]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<vector<int>>> adjm(28, vector<vector<int>>(28));
    for (int i = 0; i < n; i++) {
        char a, b;
        int c, d, e;
        cin >> a >> b >> c;
        d = a - 'a' + 1;
        e = b - 'a' + 1;
        if (a == 'X') d = 0;
        if (a == 'Y') d = 27;
        if (b == 'X') e = 0;
        if (b == 'Y') e = 27;
        adjm[min(d, e)][max(d, e)].push_back(c);
    }
    vector<vector<pair<int, double>>> adjl(28);
    for (int i = 0; i < 28; i++) {
        for (int j = 0; j < 28; j++) {
            if (adjm[i][j].size() > 0) {
                if (adjm[i][j].size() % 2 == 0) {
                    nth_element(adjm[i][j].begin(), adjm[i][j].begin() + adjm[i][j].size() / 2, adjm[i][j].end());
                    nth_element(adjm[i][j].begin(), adjm[i][j].begin() + (adjm[i][j].size() - 1) / 2, adjm[i][j].end());
                    adjl[i].push_back({j, (double)(adjm[i][j][adjm[i][j].size() / 2] + adjm[i][j][(adjm[i][j].size() - 1) / 2]) / 2.0});
                    adjl[j].push_back({i, (double)(adjm[i][j][adjm[i][j].size() / 2] + adjm[i][j][(adjm[i][j].size() - 1) / 2]) / 2.0});
                } else {
                    nth_element(adjm[i][j].begin(), adjm[i][j].begin() + adjm[i][j].size() / 2, adjm[i][j].end());
                    adjl[i].push_back({j, (double)(adjm[i][j][adjm[i][j].size() / 2])});
                    adjl[j].push_back({i, (double)(adjm[i][j][adjm[i][j].size() / 2])});
                }
            }
        }
    }
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
    q.push({0, 0});
    vector<double> dis(28, DBL_MAX);
    vector<int> par(28);
    for (int i = 0; i < 28; i++) par[i] = i;
    dis[0] = 0;
    while (!q.empty()) {
        int w = q.top().second;
        q.pop();
        for (auto i : adjl[w]) {
            if (dis[i.first] > dis[w] + i.second) {
                dis[i.first] = dis[w] + i.second;
                q.push({dis[i.first], i.first});
                // cout << i.first << ' ' << w << '\n';
                par[i.first] = w;
            }
        }
    }
    // for (int i = 0; i < adjl.size(); i++) {
    //     for (auto j : adjl[i]) {
    //         cout << i << " -> " << j.first << ' ' << j.second << '\n';
    //     }
    // }
    if (par[27] == 27) cout << "broken";
    else {
        print(par, adjl, 27);
        cout << fixed << setprecision(1) << dis[27];
    }
}