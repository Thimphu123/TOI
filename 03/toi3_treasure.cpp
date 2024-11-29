#include <bits/stdc++.h>

using namespace std;

int main() {
    double x = 0, y = 0;
    while (true) {
        int n;
        scanf("%d", &n);
        char c1, c2;
        scanf("%c", &c1);
        if (c1 == '*') break;
        scanf("%c", &c2);
        if (c1 == 'N') {
            if (c2 == 'E') {
                x += (double)(n) / sqrt(2);
                y += (double)(n) / sqrt(2);
            } else if (c2 == 'W') {
                x -= (double)(n) / sqrt(2);
                y += (double)(n) / sqrt(2);
            } else {
                y += n;
            }
        } else if (c1 == 'S') {
            if (c2 == 'E') {
                x += (double)(n) / sqrt(2);
                y -= (double)(n) / sqrt(2);
            } else if (c2 == 'W') {
                x -= (double)(n) / sqrt(2);
                y -= (double)(n) / sqrt(2);
            } else {
                y -= n;
            }
        } else if (c1 == 'W') {
            x -= n;
        } else if (c1 == 'E') {
            x += n;
        }
    }
    printf("%.3lf %.3lf\n%.3lf", x, y, sqrt(x*x + y*y));
}