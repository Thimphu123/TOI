#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, cnt = 0;
	cin >> n;
	vector<vector<int>> r(n, vector<int>(n));
	for(int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> r[i][j];
    for(int i = 0; i < n - 1; i++) for(int j = 0; j < n - 1; j++) {
        int a = r[i][j];
        int b = r[i][j + 1];
        int c = r[i + 1][j];
        int d = r[i + 1][j + 1];
        int ai = (i > 0)?r[i - 1][j]:0;
        int aj = (j > 0)?r[i][j - 1]:0;
        int bi = (i > 0)?r[i - 1][j + 1]:0;
        int bj = (j + 2 < n)?r[i][j + 2]:0;
        int ci = (i + 2 < n)?r[i + 2][j]:0;
        int cj = (j > 0)?r[i + 1][j - 1]:0;
        int di = (i + 2 < n)?r[i + 2][j + 1]:0;
        int dj = (j + 2 < n)?r[i + 1][j + 2]:0;
        if(a == b and a == c and a != d and (a != ai and a != aj) and (b != bi and b != bj) and (c != ci and c != cj)){
            cnt++;
            continue;
        }
        if(b == a and b == d and b != c and (a != ai and a != aj) and (b != bi and b != bj) and (d != di and d != dj)){
            cnt++;
            continue;
        }
        if(c == a and c == d and c != b and (a != ai and a != aj) and (d != di and d != dj) and (c != ci and c != cj)){
            cnt++;
            continue;
        }
        if(d == b and d == c and d != a and (d != di and d != dj) and (b != bi and b != bj) and (c != ci and c != cj)){
            cnt++;
            continue;
        }
    }
	cout << cnt;
}