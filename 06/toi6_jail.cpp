#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, b = 0, c = 0;
    scanf("%d%d", &n, &m);
    bool a[n] = {false};
    while (b != n) {
        for (int i = 0; i < m; i++) {
            c++;
            if (c > n) c -= n;
            if (a[c - 1]) i--;
        }
        a[c - 1] = true;
        printf("%d ", c);
        b++;
    }
}