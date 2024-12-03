#include <bits/stdc++.h>
#define p INT_MAX

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    unordered_map<string, pair<char, int>> m[4];
    m[0]["00"].first = '0';
    m[0]["00"].second = 0;
    m[0]["11"].first = '1';
    m[0]["11"].second = 1;
    m[1]["10"].first = '0';
    m[1]["10"].second = 2;
    m[1]["01"].first = '1';
    m[1]["01"].second = 3;
    m[2]["00"].first = '1';
    m[2]["00"].second = 1;
    m[2]["11"].first = '0';
    m[2]["11"].second = 0;
    m[3]["10"].first = '1';
    m[3]["10"].second = 3;
    m[3]["01"].first = '0';
    m[3]["01"].second = 2;
    cin >> n;
    string a;
    int curr = 0, sum;
    for (int j = 0; j < n; j++) {
        string temp;
        int ans = 0;
        cin >> a;
        for (int i = 0; i < a.size(); i += 2) {
            string tempp;
            tempp += a[i];
            tempp += a[i + 1];
            temp += m[curr][tempp].first;
            curr = m[curr][tempp].second;
        }
        if (a.size() != 16) continue;
        sum = 1;
        for (int i = 7; i >= 0; i--) {
            ans += sum * (temp[i] - '0');
            sum *= 2;
        }
        cout << (char)(ans);
    }
}