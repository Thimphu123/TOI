#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, u, v, w, s, d, p;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cin >> s >> d >> p;
    priority_queue<pair<int, int>> q;
    vector<int> dis(n + 1, 0);
    q.push({s, INT_MAX});
    while (!q.empty()) {
        int a = q.top().first, b = q.top().second;
        q.pop();
        for (auto i : adj[a]) {
            if (dis[i.first] < min(b, i.second)) {
                dis[i.first] = min(b, i.second);
                q.push({i.first, dis[i.first]});
            }
        }
    }
    cout << ceil((double)(p) / (double)(dis[d] - 1));
}