#include <bits/stdc++.h>

using namespace std;

long long recur(const vector<vector<bool>>& dog, vector<vector<long long>>& memo, long long a, long long b) {
    if (a < 0 or b < 0 or dog[a][b]) {
        return 0;
    }
    if (a == 0 and b == 0) {
        return 1;
    }
    if (memo[a][b] != -1) {
        return memo[a][b];
    } 
    return memo[a][b] = recur(dog, memo, a - 1, b) + recur(dog, memo, a, b - 1);
}

int main() {
    long long n, m, o, a, b;
    scanf("%lld%lld", &m, &n);
    scanf("%lld", &o);
    vector<vector<bool>> dog(m, vector<bool>(n, false));
    vector<vector<long long>> memo(m, vector<long long>(n, -1));
    for (long long i = 0; i < o; i++) {
        scanf("%lld%lld", &a, &b);
        dog[a - 1][b - 1] = true;
    }
    printf("%lld", recur(dog, memo, m - 1, n - 1));
}