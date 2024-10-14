#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    int start = 0, stop, sum = 0, msum = 0, temp;
    for (int i = 0; i < n; i++) {
        if (nums[i] > sum + nums[i]) temp = i;
        sum = max(sum + nums[i], nums[i]);
        if (sum > msum) {
            start = temp;
            stop = i;
        }
        msum = max(msum, sum);
    }
    if (msum == 0) {
        printf("Empty sequence");
        return 0;
    }
    for (int i = start; i <= stop; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n%d", msum);
}