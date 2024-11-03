#include <bits/stdc++.h>

using namespace std;

int main(){
    int m, t;
    long long n;
    scanf("%d%lld", &m, &n);
    vector<int> worker(m);
    for (int i = 0; i < m; i++) scanf("%d", &worker[i]);
    long long l = 1, r = 1e12;
    while (l < r) {
        long long sum = 0, mid = l + (r - l) / 2;
        for (int i = 0; i < m; i++) sum += mid / worker[i];
        if (sum < n) l = mid + 1;
        else r = mid;
    }
    printf("%lld", l);
}