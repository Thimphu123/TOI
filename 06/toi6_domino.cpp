#include <bits/stdc++.h>

using namespace std;

void recur(int a, string b, int n) {
    if (a == n) cout << b << "E\n";
    else if (a < n) {
        recur(a + 1, b + "--\n", n);
        recur(a + 2, b + "||\n", n);
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    recur(0, "", n);
}