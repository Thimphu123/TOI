#include <bits/stdc++.h>

using namespace std;

int main() {
    int l, n, check;
    scanf("%d", &l);
    scanf("%d", &n);
    string c, d;
    cin >> c;
    for (int i = 1; i < n; i++) {
        cin >> d;
        check = 0;
        for (int j = 0; j < l; j++) {
            if (c[j] != d[j]) {
                check++;
                if (check > 2) {
                    cout << c;
                    return 0;
                }
            }
        }
        c = d;
    }
    cout << c;
}