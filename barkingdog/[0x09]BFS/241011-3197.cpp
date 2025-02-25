#include "../../algorithm-frame.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int R, C;
vector<vector<char>> board;
vector<vector<int>> visited;
deque<pair<int, int>> dq;
int answer;

void input() {
    cin >> R >> C;
    board = vector(R, vector<char>(C));
    visited = vector(R, vector(C, -1));
    while( !dq.empty())
        dq.pop_back();
    answer = 0;

    string inp;
    int birdOrder = 0;
    for (int i = 0; i < R; i++) {
        cin >> inp;
        for (int j = 0; j < C; j++) {
            board[i][j] = inp[j];
            if (inp[j] == 'L') {
                board[i][j] = 'A' + birdOrder++;
                dq.push_front({i, j});
                visited[i][j] = 0;
            } else if (inp[j] == '.') {
                dq.push_back({i, j});
            }
        }
    }
}

void solution() {
    while (!dq.empty()) {
        pair<int, int> cur = dq.front();
        dq.pop_front();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C)
                continue;

            if (board[cur.first][cur.second] == '.') {
                if (board[nx][ny] == 'X') {
                    board[nx][ny] = '.';
                    dq.push_back({nx, ny});
                }
            } else {
                if (board[nx][ny] == '.') {
                    board[nx][ny] = board[cur.first][cur.second];
                    visited[nx][ny] = visited[cur.first][cur.second];
                    dq.push_front({nx, ny});
                }
                else if (board[nx][ny] == 'X') {
                    board[nx][ny] = board[cur.first][cur.second];
                    visited[nx][ny] = visited[cur.first][cur.second] + 1;
                    dq.push_back({nx, ny});
                } else if (board[nx][ny] != board[cur.first][cur.second]) {
                    answer = visited[nx][ny];
                    return;
                }
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
