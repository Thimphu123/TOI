#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, ans = 0;
    cin >> n;
    while (n > 0) {
        if (n >= 10) {
            n -= 15;
            ans += 3000;
        } else if (n >= 4) {
            n -= 5;
            ans += 1500;
        } else if (n >= 2) {
            n -= 2;
            ans += 800;
        } else if (n >= 1) {
            n -= 1;
            ans += 500;
        }
    }
    cout << ans;
}