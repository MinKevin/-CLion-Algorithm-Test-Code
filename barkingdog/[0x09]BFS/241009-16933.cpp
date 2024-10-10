#include "../../algorithm-frame.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

ostringstream oss;

struct A {
    int x;
    int y;
    int distance;
    int breakWallCount;
    bool isNight;
};

struct B {
    bool visited;
    int breakWallCount;
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int N, M, K;
vector<vector<int> > board;
vector<vector<B> > vis;

void input() {
    oss.str("");
    oss.clear();

    cin >> N >> M >> K;

    board = vector(N, vector<int>(M));
    vis = vector(N, vector<B>(M));

    string inp;
    for (int i = 0; i < N; i++) {
        cin >> inp;
        for (int j = 0; j < M; j++) {
            board[i][j] = inp[j] - '0';
        }
    }
}

void solution() {
    if (N == 1 && M == 1) {
        oss << 1 << '\n';
        return;
    }

    queue<A> q;
    q.push({0, 0, 1, 0, false});
    vis[0][0] = {true, 0};

    while (!q.empty()) {
        A cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;

            if (nx == N - 1 && ny == M - 1) {
                oss << cur.distance + 1 << '\n';
                return;
            }

            if (board[nx][ny] == 0) {
                if (vis[nx][ny].visited == false ||
                    vis[nx][ny].breakWallCount > cur.breakWallCount) {
                    vis[nx][ny] = {true, cur.breakWallCount};
                    q.push({nx, ny, cur.distance + 1, cur.breakWallCount, !cur.isNight});
                }
            } else {
                if (cur.isNight) {
                    q.push({cur.x, cur.y, cur.distance + 1, cur.breakWallCount, !cur.isNight});
                } else {
                    if (vis[nx][ny].visited == false && cur.breakWallCount < K ||
                        vis[nx][ny].breakWallCount > cur.breakWallCount + 1) {
                        vis[nx][ny] = {true, cur.breakWallCount + 1};
                        q.push({nx, ny, cur.distance + 1, cur.breakWallCount + 1, !cur.isNight});
                    }
                }
            }
        }
    }

    oss << -1 << '\n';
}

void output() {
    cout << oss.str();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    streambuf *pCoutStreamBuf = cout.rdbuf();
    cout.rdbuf(oss.rdbuf());

    input();

    solution();

    cout.rdbuf(pCoutStreamBuf);
    output();
}
