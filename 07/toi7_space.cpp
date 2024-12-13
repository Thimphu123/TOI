#include <bits/stdc++.h>

using namespace std;

void recur(vector<int>& aa, int i) {
    if (i == 0) {
        for (int k = 0; k < aa.size(); k++) {
            if (aa[k]) continue;
            for (int i = aa.size() - 1; i >= 0; i--) printf("%d", aa[i]);
            printf(" ");
            aa[k] = 1;
            for (int i = aa.size() - 1; i >= 0; i--) printf("%d", aa[i]);
            aa[k] = 0;
            printf("\n");
        }
    } else {
        aa[i - 1] = 0;
        recur(aa, i - 1);
        aa[i - 1] = 1;
        recur(aa, i - 1);
    }
}

int main() {
    int d;
    scanf("%d", &d);
    vector<int> a(d, 0);
    recur(a, d);
}