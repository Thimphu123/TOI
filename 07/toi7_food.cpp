#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	vector<bool> b(n + 1, true);
	vector<int> ans;
	for (int i = 0; i < m; i++) {
		int a;
		scanf("%d", &a);
		b[a] = false;
	}
	for (int i = 1; i <= n; i++) {
		ans.push_back(i);
	}
	do {
		if (!b[ans[0]]) continue;
		for (auto j: ans) printf("%d ", j);
		printf("\n");
	} while (next_permutation(ans.begin(), ans.end()));
}