#include <bits/stdc++.h>

using namespace std;

int md(int a) {
    if (a % 9 == 0) return 9;
    else return a % 9;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    int f = a[0] - '0' - 1, s = a[1] - '0' - 1, t = a[2] - '0' - 1;
    for (int i = 0; i < b.size(); i++) {
        cout << md(b[i] - '0' + f + s + t);
        f = md(f + (a[0] - '0'));
        s = md(s + 8);
        t = md(t + (a[2] - '0'));
    }
}