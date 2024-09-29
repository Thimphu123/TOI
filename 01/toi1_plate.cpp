#include <bits/stdc++.h>

using namespace std;

int main() {
    int nc, ns;
    scanf("%d%d", &nc, &ns);
    unordered_map<int, int> students;
    queue<int> q, bq[nc];
    for (int i = 0; i < ns; i++) {
        int student[2];
        scanf("%d%d", &student[0], &student[1]);
        students[student[1]] = student[0];
    }
    char command = 'A';
    while (command != 'X') {
        int id;
        cin >> command;
        if (command == 'E') {
            scanf("%d", &id);
            if (bq[students[id] - 1].empty()) {
                q.push(students[id]);
            }
            bq[students[id] - 1].push(id);
        } else if (command == 'D') {
            printf("%d", bq[q.front() - 1].front());
            printf("\n");
            bq[q.front() - 1].pop();
            if (bq[q.front() - 1].empty()) {
                q.pop();
            }
        }
    }
    printf("%d", 0);
}