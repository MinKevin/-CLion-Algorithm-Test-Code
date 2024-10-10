#include "../../algorithm-frame.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

struct player {
    int round;
    int id;
    int remainDistance;
    int x;
    int y;
};

struct cmp {
    bool operator()(player a, player b) {
        if (a.round != b.round) {
            return a.round > b.round;
        }
        if (a.id != b.id) {
            return a.id > b.id;
        }
        return a.remainDistance < b.remainDistance;
    }
};

int N, M, P;
vector<vector<char>> board;
vector<int> availableDistance;
priority_queue<player, vector<player>, cmp> pq;
vector<int> answer;

void input() {
    cin >> N >> M >> P;

    board = vector(N, vector<char>(M));
    availableDistance = vector<int>(P + 1, 0);
    answer = vector<int>(P + 1, 0);

    for (int i = 1; i <= P; i++) {
        cin >> availableDistance[i];
    }

    string inp;
    for (int i = 0; i < N; i++) {
        cin >> inp;
        for (int j = 0; j < M; j++) {
            board[i][j] = inp[j];
            if (inp[j] >= '1' && inp[j] <= '9') {
                pq.push({0, inp[j] - '0', availableDistance[inp[j] - '0'], i, j});
                answer[inp[j] - '0']++;
            }
        }
    }
}

void solution() {
    while(!pq.empty()) {
        player cur = pq.top();
        pq.pop();

        //cout << cur.round << ' ' <<cur.id << ' ' << cur.remainDistance << ' ' << cur.x << ' ' << cur.y <<'\n';
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;

            if (board[nx][ny] == '.') {
                board[nx][ny] = cur.id + '0';
                answer[cur.id]++;
                if (cur.remainDistance > 1)
                    pq.push({cur.round, cur.id, cur.remainDistance - 1, nx, ny});
                else
                    pq.push({cur.round + 1, cur.id, availableDistance[cur.id], nx, ny});
            }
        }
    }
}

void output() {
    for (int i = 1; i <= P; i++)
        cout << answer[i] << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
