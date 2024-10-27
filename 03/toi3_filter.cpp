#include <bits/stdc++.h>

using namespace std;

int main() {
    int w, h, n, aw = 0, ah = 0;
    scanf("%d%d%d", &w, &h, &n);
    vector<int> filter(w);
    while (n--) {
        int x, a;
        scanf("%d%d", &x, &a);
        for (int i = x; i < min(w, x + a); i++) {
            if (filter[i] == 1) filter[i]++;
            else if (filter[i] != 2) filter[i] = 1;
        }
    }
    for (int i = 0; i < w; i++) {
        if (filter[i] == 1) aw++;
        else if (filter[i] != 2) ah++;
    }
    printf("%d %d", h * ah, h * aw);
}