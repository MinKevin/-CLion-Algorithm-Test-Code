#include "../../algorithm-frame.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int N, M;
vector<vector<vector<pair<int, int> > > > lightSwitch;
vector<vector<int> > board;
vector<vector<int> > vis;
int answer;

void input() {
    cin >> N >> M;
    lightSwitch = vector(N, vector(N, vector<pair<int, int> >()));
    board = vector(N, vector(N, 0));
    vis = vector(N, vector(N, 0));
    answer = 1;

    int x, y, a, b;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> a >> b;
        lightSwitch[x - 1][y - 1].push_back({a - 1, b - 1});
    }
}

void solution() {
    board[0][0] = 1;
    vis[0][0] = 1;
    queue<pair<int, int> > q;
    q.push({0, 0});

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < lightSwitch[cur.first][cur.second].size(); i++) {
            pair<int, int> nextLightSwitch = lightSwitch[cur.first][cur.second][i];
            if (board[nextLightSwitch.first][nextLightSwitch.second] == 0) {
                board[nextLightSwitch.first][nextLightSwitch.second] = 1;
                answer++;

                for (int dir = 0; dir < 4; dir++) {
                    int nx = nextLightSwitch.first + dx[dir];
                    int ny = nextLightSwitch.second + dy[dir];

                    if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                        continue;

                    if (board[nx][ny] == 1 && vis[nx][ny] == 1) {
                        q.push({nextLightSwitch.first, nextLightSwitch.second});
                        vis[nextLightSwitch.first][nextLightSwitch.second] = 1;
                    }
                }
            }
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                continue;

            if (board[nx][ny] == 1 && vis[nx][ny] == 0) {
                q.push({nx, ny});
                vis[nx][ny] = 1;
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
