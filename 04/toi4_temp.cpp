#include <bits/stdc++.h>

using namespace std;

bool check(const vector<vector<int>>& arr, int x, int y) {
    if (x < 0 or y < 0 or x >= arr.size() or y >= arr.size()) return true;
    if (arr[x][y] == 100) return true;
    return false;
}

int recur(const vector<vector<int>>& arr, int x, int y) {
    if ((check(arr, x + 1, y) or arr[x + 1][y] <= arr[x][y]) and (check(arr, x - 1, y) or arr[x - 1][y] <= arr[x][y]) and (check(arr, x, y + 1) or arr[x][y + 1] <= arr[x][y]) and (check(arr, x, y - 1) or arr[x][y - 1] <= arr[x][y])) return arr[x][y];
    int maxx = -6;
    if (!check(arr, x - 1, y) and arr[x - 1][y] > arr[x][y]) maxx = max(maxx, recur(arr, x - 1, y));
    if (!check(arr, x + 1, y) and arr[x + 1][y] > arr[x][y]) maxx = max(maxx, recur(arr, x + 1, y));
    if (!check(arr, x, y - 1) and arr[x][y - 1] > arr[x][y]) maxx = max(maxx, recur(arr, x, y - 1));
    if (!check(arr, x, y + 1) and arr[x][y + 1] > arr[x][y]) maxx = max(maxx, recur(arr, x, y + 1));
    return maxx;
}

int main() {
    int m, x, y;
    scanf("%d", &m);
    scanf("%d%d", &x, &y);
    vector<vector<int>> arr(m, vector<int>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[j][i]);
        }
    }
    printf("%d", recur(arr, x - 1, y - 1));
}