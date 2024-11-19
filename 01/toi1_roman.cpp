#include <bits/stdc++.h>

using namespace std;

int i = 0, v = 0, x = 0, l = 0, c = 0;

void calculate(int d) {
    while (d >= 100) {
        d -= 100;
        c++;
    }
    while (d >= 90) {
        d-= 90;
        c++;
        x++;
    }
    while (d >= 50) {
        d -= 50;
        l++;
    }
    while (d >= 40) {
        d -= 40;
        l++;
        x++;
    }
    while (d >= 10) {
        d -= 10;
        x++;
    }
    while (d >= 9) {
        d -= 9;
        x++;
        i++;
    }
    while (d >= 5) {
        d -= 5;
        v++;
    }
    while (d >= 4) {
        d -= 4;
        v++;
        i++;
    }
    i += d;
}

int main() {
    int d;
    scanf("%d", &d);
    for (int i = 1; i <= d; i++) calculate(i);
    printf("%d %d %d %d %d", i, v, x, l, c);
}