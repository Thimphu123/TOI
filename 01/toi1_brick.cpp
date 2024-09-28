#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<string> a(n);
    vector<int> c(m, n);
    for (int i = 0; i < n; i++) {
        string b;
        cin >> b;
        a[i] = b;
        for (int j = 0; j < m; j++) {
            if (b[j] == 'O' and i < c[j]) {
                c[j] = i;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        int d;
        scanf("%d", &d);
        for (int i = c[j] - 1; i > c[j] - 1 - min(c[j], d); i--) {
                a[i][j] = '#';
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i];
        printf("\n");
    }
}