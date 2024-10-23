#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a = 0, b = 0, c = 0, d = 0, e = 0;
    scanf("%d", &n);
    while (n--) {
        int ta, tb, tc, td, te;
        scanf("%d%d%d%d%d", &ta, &tb, &tc, &td, &te);
        a += ta;
        b += tb;
        c += tc;
        d += td;
        e += te;
    }
    while (b > 0) {
        if (d > 0) {
            a++;
            d--;
            b--;
        } else if (e > 1) {
            a++;
            e -= 2;
            b--;
        } else if (e > 0) {
            a++;
            e--;
            b--;
        } else {
            b--;
            a++;
        }
    }
    while (c > 0) {
        if (c > 1) {
            a++;
            c -= 2;
        } else if (d > 1) {
            a++;
            d -= 2;
            c--;
        } else if (d > 0) {
            if (e > 1) {
                a++;
                e -= 2;
                d--;
                c--;
            } else if (e > 0) {
                a++;
                e--;
                d--;
                c--;
            } else {
                a++;
                d--;
                c--;
            }
        } else if (e > 3) {
            a++;
            e -= 4;
            c--;
        } else {
            a++;
            e = 0;
            c--;
        }
    }
    while (d > 0) {
        if (d > 3) {
            a++;
            d -= 4;
        } else {
            a++;
            e -= (4 - d) * 2;
            d = 0;
        }
    }
    a += ceil(double(e) / 8);
    printf("%d", a);
}