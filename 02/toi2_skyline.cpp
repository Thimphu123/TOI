#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, h = 0, temp = 0;
    scanf("%d", &n);
    vector<int> sky(256, 0);
    while (n--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        for (int i = a; i < c; i++) {
            sky[i] = max(sky[i], b);
        }
        h = max(h, c);
    }
    for (int i = 1; i <= h; i++) {
        if (temp != sky[i]) {
            printf("%d %d ", i, sky[i]);
            temp = sky[i];
        }
    }
}