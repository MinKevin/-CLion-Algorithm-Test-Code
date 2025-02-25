#include "../../algorithm-frame.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct person {
    string name;
    int loc;
    int time;
};

int dx[2] = {1, -1};

int N, K;
vector<vector<int>> visited;
int answer;

void input() {
    cin >> N >> K;
    visited = vector(500001, vector(2, 0));
    answer = -1;
}

void solution() {
    if (N == K) {
        answer = 0;
        return;
    }

    queue<person> q;
    visited[N][0] = 1;
    q.push({"Subin", N, 1});
    q.push({"Brother", K, 1});

    while (!q.empty()) {
        person cur = q.front();
        q.pop();

        if (cur.name == "Subin") {
            for (int dir = 0; dir < 3; dir++) {
                int nx;
                if (dir == 2) {
                    nx = cur.loc * 2;
                }
                else {
                    nx = cur.loc + dx[dir];
                }

                if (nx < 0 || nx > 500000)
                    continue;

                if (visited[nx][cur.time % 2] == 0) {
                    visited[nx][cur.time % 2] = 1;
                    q.push({"Subin", nx, cur.time + 1});
                }
            }
        } else {
            int nx = cur.loc + cur.time;

            if (nx > 500000) {
                answer = -1;
                return;
            }
            if (visited[nx][cur.time % 2] == 1) {
                answer = cur.time;
                return;
            } else {
                q.push({"Brother", nx, cur.time + 1});
            }
        }
    }
}

void output() {
    cout << answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
