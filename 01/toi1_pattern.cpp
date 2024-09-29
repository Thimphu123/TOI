#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, p, q, r, maxrow = 0;
    scanf("%d", &n);
    vector<string> ans(n, "oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo");
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &p, &q, &r);
        maxrow = max(p, maxrow);
        p--;
        for (int j = q - 1; (j < r + q - 1) and j < 70; j++) {
            ans[p][j] = 'x';
        }
    }
    for (int i = 0; i < maxrow; i++) {
        cout << ans[i];
        printf("\n");
    }
}