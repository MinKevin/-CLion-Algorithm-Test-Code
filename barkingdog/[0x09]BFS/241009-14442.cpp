#include "../../algorithm-frame.h"
#include <sstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

ostringstream oss;

struct A {
    int x;
    int y;
    int breakWallCounter;
};

struct B {
    int distance;
    int breakWallCounter;
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
    board = vector(N, vector<int>(M, 0));
    vis = vector(N, vector<B>(M, {0, 0}));

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
    vis[0][0] = {1, 0};
    queue<A> q;
    q.push({0, 0, 0});

    while (!q.empty()) {
        A cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;

            if (nx == N - 1 && ny == M - 1) {
                oss << vis[cur.x][cur.y].distance + 1 << '\n';
                return;
            }


            if (board[nx][ny] == 0) {
                if (vis[nx][ny].distance == 0 || vis[nx][ny].breakWallCounter > cur.breakWallCounter) {
                    vis[nx][ny] = {vis[cur.x][cur.y].distance + 1, cur.breakWallCounter};
                    q.push({nx, ny, cur.breakWallCounter});
                }
            } else {
                if (vis[nx][ny].distance == 0 && cur.breakWallCounter < K || vis[nx][ny].breakWallCounter > cur.breakWallCounter + 1) {
                    vis[nx][ny] = {vis[cur.x][cur.y].distance + 1, cur.breakWallCounter + 1};
                    q.push({nx, ny, cur.breakWallCounter + 1});
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
