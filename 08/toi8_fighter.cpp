#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int p1, a, cnt1 = 0, p2, cnt2 = 0;
    cin >> p1;
    p2 = p1;
    while (p1 > 0 and p2 > 0) {
        cin >> a;
        if (a % 2) {
            cnt2 = 0;
            cnt1++;
            if (cnt1 >= 3) {
                p2 -= 3;
            } else {
                p2--;
            }
        } else {
            cnt1 = 0;
            cnt2++;
            if (cnt2 >= 3) {
                p1 -= 3;
            } else {
                p1--;
            }
        }
    }
    if (p2 <= 0) cout << "1\n" << a;
    else if (p1 <= 0) cout << "0\n" << a;
}