#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    vector<vector<char>> graph(a, vector<char>(b));
    for (int i = 0; i < a; i++) for (int j = 0; j < b; j++) cin >> graph[i][j];
    vector<vector<int>> visited(a, vector<int>(b, 0));
    visited[0][0] = 1;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        int c = q.front().first, d = q.front().second;
        q.pop();
        if (graph[c][d] == 'B') {
            if (d + 1 < b) {
                if (visited[c][d + 1] == visited[c][d] + 1) {
                    cout << visited[c][d + 1] << '\n' << c + 1 << ' ' << d + 2;
                    return 0;
                }
                if (visited[c][d + 1] == 0) {
                    visited[c][d + 1] = visited[c][d] + 1;
                    q.push({c, d + 1});
                }
            }
            if (c + 1 < a) {
                if (visited[c + 1][d] == visited[c][d] + 1) {
                    cout << visited[c + 1][d] << '\n' << c + 2 << ' ' << d + 1;
                    return 0;
                }
                if (visited[c + 1][d] == 0) {
                    visited[c + 1][d] = visited[c][d] + 1;
                    q.push({c + 1, d});
                }
            }
        } else if (graph[c][d] == 'R') {
            if (d + 1 >= b) continue; 
            if (visited[c][d + 1] == visited[c][d] + 1) {
                cout << visited[c][d + 1] << '\n' << c + 1 << ' ' << d + 2;
                return 0;
            }
            if (visited[c][d + 1] == 0) {
                visited[c][d + 1] = visited[c][d] + 1;
                q.push({c, d + 1});
            }
        } else if (graph[c][d] == 'D') {
            if (c + 1 >= a) continue;
            if (visited[c + 1][d] == visited[c][d] + 1) {
                cout << visited[c + 1][d] << '\n' << c + 2 << ' ' << d + 1;
                return 0;
            }
            if (visited[c + 1][d] == 0) {
                visited[c + 1][d] = visited[c][d] + 1;
                q.push({c + 1, d});
            }
        }
        if (d > 0 and (graph[c][d - 1] == 'B' or graph[c][d - 1] == 'R')) {
            if (visited[c][d - 1] == visited[c][d] + 1) {
                cout << visited[c][d - 1] << '\n' << c + 1 << ' ' << d;
                return 0;
            }
            if (visited[c][d - 1] == 0) {
                visited[c][d - 1] = visited[c][d] + 1;
                q.push({c, d - 1});
            }
        }
        if (c > 0 and (graph[c - 1][d] == 'B' or graph[c - 1][d] == 'D')) {
            if (visited[c - 1][d] == visited[c][d] + 1) {
                cout << visited[c - 1][d] << '\n' << c << ' ' << d + 1;
                return 0;
            }
            if (visited[c - 1][d] == 0) {
                visited[c - 1][d] = visited[c][d] + 1;
                q.push({c - 1, d});
            }
        }
    }
}