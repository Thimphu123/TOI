#include <bits/stdc++.h>

using namespace std;

void dfs(const vector<vector<pair<int, int>>>& adj, vector<bool>& visited, int a) {
    for (auto i : adj[a]) {
        if (!visited[i.second]) {
            visited[i.second] = true;
            dfs(adj, visited, i.first);
        }
    }
    cout << (char)('A' + a) << ' ';
}

int main() {
    int n;
    cin >> n;
    vector<int> deg(26, 0);
    vector<vector<pair<int, int>>> adj(26);
    vector<bool> visited(n);
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        adj[s[0] - 'A'].push_back({s[1] - 'A', i});
        adj[s[1] - 'A'].push_back({s[0] - 'A', i});
        deg[s[0] - 'A']++;
        deg[s[1] - 'A']++;
    }
    for (int i = 0; i < 26; i++) {
        if (deg[i] % 2 == 1) {
            dfs(adj, visited, i);
            return 0;
        }
    }
    dfs(adj, visited, 0);
}