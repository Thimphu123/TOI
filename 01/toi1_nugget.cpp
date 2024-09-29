#include <bits/stdc++.h>

using namespace std;

void nugget(int n, int t, vector<int>& ans) {
    if (t <= n) {
        if (t != 0) {
            ans.push_back(t);
        }
        nugget(n, t + 6, ans);
        nugget(n, t + 9, ans);
        nugget(n, t + 20, ans);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> ans;
    if (n < 6) {
        printf("no");
    } else {
        nugget(n, 0, ans);
        sort(ans.begin(), ans.end());
        auto it = unique(ans.begin(), ans.end());
        ans.erase(it, ans.end());
        for (int i = 0; i < ans.size(); i++) {
            printf("%d", ans[i]);
            printf("\n");
        }
    }
}