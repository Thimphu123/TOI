#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, c = 0;
    scanf("%d", &n);
    vector<bool> a(8000001, false);
    for (int i = 2; i <= 8000000; i++) {
        if (!a[i]) {
            c++;
            if (c == n) printf("%d", i);
            for (int j = 2 * i; j <= 8000000; j += i) {
                a[j] = true;
            }
        }
    }
}