#include "../../algorithm-frame.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

ostringstream oss;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int T;
vector<int> h, w;
vector<vector<vector<char> > > board;
vector<vector<vector<int> > > vis;
vector<vector<bool> > keys;
vector<vector<queue<pair<int, int> > > > doors;
vector<queue<pair<int, int> > > qs;
vector<int> answer;
void input() {
    cin >> T;

    h = vector(T, 0);
    w = vector(T, 0);

    keys = vector(T, vector<bool>(26, false));
    qs = vector(T, queue<pair<int, int> >());
    answer = vector(T, 0);

    for (int i = 0; i < T; i++) {
        cin >> h[i] >> w[i];
        board.push_back(vector(h[i], vector<char>(w[i], NULL)));
        vis.push_back(vector(h[i], vector<int>(w[i], 0)));
        doors.push_back(vector<queue<pair<int, int> > >(26));
        string inp;
        for (int j = 0; j < h[i]; j++) {
            cin >> inp;
            for (int k = 0; k < w[i]; k++) {
                board[i][j][k] = inp[k];

                if (j == 0 || k == 0 || j == h[i] - 1 || k == w[i] - 1) {
                    if (inp[k] == '.') {
                        qs[i].push({j, k});
                        vis[i][j][k] = 1;
                    } else if (inp[k] >= 'A' && inp[k] <= 'Z') {
                        if (keys[i][inp[k] - 'A'] == true) {
                            vis[i][j][k] = 1;
                            qs[i].push({j, k});
                        } else {
                            doors[i][inp[k] - 'A'].push({j, k});
                        }
                    } else if (inp[k] >= 'a' && inp[k] <= 'z') {
                        keys[i][inp[k] - 'a'] = true;
                        qs[i].push({j, k});
                        vis[i][j][k] = 1;
                    } else if (inp[k] == '$') {
                        answer[i]++;
                        qs[i].push({j, k});
                        vis[i][j][k] = 1;
                    }
                }
            }
        }

        string keySet;
        cin >> keySet;
        if (keySet != "0") {
            for (int j = 0; j < keySet.size(); j++) {
                keys[i][keySet[j] - 'a'] = true;
                while (!doors[i][keySet[j] - 'a'].empty()) {
                    qs[i].push(doors[i][keySet[j] - 'a'].front());
                    doors[i][keySet[j] - 'a'].pop();
                }
            }
        }
    }
}

void solution() {
    for (int t = 0; t < T; t++) {
        while (!qs[t].empty()) {
            pair<int, int> cur = qs[t].front();
            qs[t].pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 0 || ny < 0 || nx >= h[t] || ny >= w[t])
                    continue;

                if (vis[t][nx][ny] == 0) {
                    if (board[t][nx][ny] == '.') {
                        vis[t][nx][ny] = 1;
                        qs[t].push({nx, ny});
                    } else if (board[t][nx][ny] == '$') {
                        vis[t][nx][ny] = 1;
                        qs[t].push({nx, ny});
                        answer[t]++;
                    } else if (board[t][nx][ny] >= 'A' && board[t][nx][ny] <= 'Z') {
                        if (keys[t][board[t][nx][ny] - 'A'] == true) {
                            vis[t][nx][ny] = 1;
                            qs[t].push({nx, ny});
                        } else {
                            doors[t][board[t][nx][ny] - 'A'].push({nx, ny});
                        }
                    } else if (board[t][nx][ny] >= 'a' && board[t][nx][ny] <= 'z') {
                        vis[t][nx][ny] = 1;
                        qs[t].push({nx, ny});
                        keys[t][board[t][nx][ny] - 'a'] = true;
                        while (!doors[t][board[t][nx][ny] - 'a'].empty()) {
                            qs[t].push(doors[t][board[t][nx][ny] - 'a'].front());
                            doors[t][board[t][nx][ny] - 'a'].pop();
                        }
                    }
                }
            }
        }
        oss << answer[t] << '\n';
    }
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
