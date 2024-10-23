#include <stdio.h>

long long pow(long long a, long long b) {
    long long c = 1;
    while (b--) c *= a;
    return c;
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    char nums[3 * n][3];
    char num[3 * m][3];
    long long inum = 0, inums = 0, temp;
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3 * n; i += 3) {
            getchar();
            scanf("%c%c%c", &nums[i][j], &nums[i + 1][j], &nums[i + 2][j]);
        }
    }
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3 * m; i += 3) {
            getchar();
            scanf("%c%c%c", &num[i][j], &num[i + 1][j], &num[i + 2][j]);
        }
    }
    temp = pow(10, n - 1);
    for (int i = 0; i < 3 * n; i += 3) {
        if (nums[i + 1][0] == '_') {
            if (nums[i + 1][1] == '_') {
                if (nums[i][1] == '|' && nums[i + 2][1] == '|') {
                    if (nums[i][2] == '|') inums += temp * 8;
                    else inums += temp * 9;
                } else if (nums[i][1] == '|') {
                    if (nums[i][2] == '|') inums += temp * 6;
                    else inums += temp * 5;
                } else if (nums[i + 2][1] == '|') {
                    if (nums[i][2] == '|') inums += temp * 2;
                    else inums += temp * 3;
                }
            } else if (nums[i][2] != '|') inums += temp * 7;
        } else {
            if (nums[i + 1][1] == '_') inums += temp * 4;
            else inums += temp * 1;
        }
        temp /= 10;
    }
    temp = pow(10, m - 1);
    for (int i = 0; i < 3 * m; i += 3) {
        if (num[i + 1][0] == '_') {
            if (num[i + 1][1] == '_') {
                if (num[i][1] == '|' && num[i + 2][1] == '|') {
                    if (num[i][2] == '|') inum += temp * 8;
                    else inum += temp * 9;
                } else if (num[i][1] == '|') {
                    if (num[i][2] == '|') inum += temp * 6;
                    else inum += temp * 5;
                } else if (num[i + 2][1] == '|') {
                    if (num[i][2] == '|') inum += temp * 2;
                    else inum += temp * 3;
                }
            } else if (num[i][2] != '|') inum += temp * 7;
        } else {
            if (num[i + 1][1] == '_') inum += temp * 4;
            else inum += temp * 1;
        }
        temp /= 10;
    }
    printf("%lld", inum + inums);
}