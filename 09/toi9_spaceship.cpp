#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef struct {
    int px, py, pz, pm, pk, pc;
} shop;

int n, x, y, z, m;
bool visited[11];

int recur(vector<shop>& a, int mm, int kk, int cc, int i) {
    if (mm >= n and kk >= n and cc >= n) return 0;
    int mn = INT_MAX, nx = a[i].px, ny = a[i].py, nz = a[i].pz;
    for (int j = 1; j <= m; j++) {
        if (visited[j]) continue;
        visited[j] = true;
        mn = min(mn, recur(a, mm + a[j].pm, kk + a[j].pk, cc + a[j].pc, j) + (nx - a[j].px) * (nx - a[j].px) + (ny - a[j].py) * (ny - a[j].py) + (nz - a[j].pz) * (nz - a[j].pz));
        visited[j] = false;
    }
    return mn;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> x >> y >> z >> m;
    vector<shop> a(m + 1);
    a[0] = {x, y, z, 0, 0, 0};
    for (int i = 1; i <= m; i++) cin >> a[i].px >> a[i].py >> a[i].pz >> a[i].pm >> a[i].pk >> a[i].pc;
    cout << recur(a, 0, 0, 0, 0);
}
