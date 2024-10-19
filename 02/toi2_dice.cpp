#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, temp;
    scanf("%d", &n);
    while (n--) {
        int dice[6] = {1, 2, 3, 5, 4, 6};
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'F') {
                temp = dice[0];
                dice[0] = dice[3];
                dice[3] = dice[5];
                dice[5] = dice[1];
                dice[1] = temp;
            } else if (s[i] == 'B') {
                temp = dice[0];
                dice[0] = dice[1];
                dice[1] = dice[5];
                dice[5] = dice[3];
                dice[3] = temp;
            } else if (s[i] == 'L') {
                temp = dice[0];
                dice[0] = dice[4];
                dice[4] = dice[5];
                dice[5] = dice[2];
                dice[2] = temp;
            } else if (s[i] == 'R') {
                temp = dice[0];
                dice[0] = dice[2];
                dice[2] = dice[5];
                dice[5] = dice[4];
                dice[4] = temp;
            } else if (s[i] == 'C') {
                temp = dice[1];
                dice[1] = dice[4];
                dice[4] = dice[3];
                dice[3] = dice[2];
                dice[2] = temp;
            } else if (s[i] == 'D') {
                temp = dice[1];
                dice[1] = dice[2];
                dice[2] = dice[3];
                dice[3] = dice[4];
                dice[4] = temp;
            }
        }
        printf("%d ", dice[1]);
    }
}