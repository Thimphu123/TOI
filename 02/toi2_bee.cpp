#include <bits/stdc++.h>

using namespace std;

int recur(int i) {
    if (i == 1 or i == 0) return i;
    return recur(i - 1) + recur(i - 2) + 1;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n != -1) {
        printf("%d %d\n", recur(n + 1), recur(n + 2));
        scanf("%d", &n);
    }
}