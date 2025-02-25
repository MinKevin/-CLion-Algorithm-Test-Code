#include <sstream>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct visitedInfo {
    int time;
    char color;
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int N, M, G, R;
vector<vector<int>> board;
vector<vector<visitedInfo>> visited;
vector<pair<int, int>> soil;
vector<int> soilVisited;
int answer;
void input() {
    cin >> N >> M >> G >> R;
    board = vector(N, vector(M, 0));
    visited = vector(N, vector<visitedInfo>(M, {-1, NULL}));
    soil.clear();
    answer = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2)
                soil.push_back({i, j});
        }
    }
    soilVisited = vector(soil.size(), 0);
}
void countFlowers() {
    struct queueInfo {
        int x;
        int y;
        int time;
        char color;
    };
    visited = vector(N, vector<visitedInfo>(M, {-1, NULL}));
    queue<queueInfo> q;
    for (int i = 0; i < soil.size(); i++) {
        if (soilVisited[i] == 2) {
            q.push({soil[i].first, soil[i].second, 0, 'G'});
            visited[soil[i].first][soil[i].second] = {0, 'G'};
        }
        else if (soilVisited[i] == 1) {
            q.push({soil[i].first, soil[i].second, 0, 'R'});
            visited[soil[i].first][soil[i].second] = {0, 'R'};
        }
    }

    int answerBuf = 0;
    while (!q.empty()) {
        queueInfo qInfo = q.front();
        q.pop();

        if (visited[qInfo.x][qInfo.y].color == 'F')
            continue;

        for (int dir = 0; dir < 4; dir++) {
            int nx = qInfo.x + dx[dir];
            int ny = qInfo.y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;

            if (visited[nx][ny].time == -1 && board[nx][ny] >= 1) {
                visited[nx][ny].time = qInfo.time + 1;
                visited[nx][ny].color = qInfo.color;
                q.push({nx, ny, qInfo.time + 1, qInfo.color});
            }

            else if (visited[nx][ny].time == qInfo.time + 1 &&
                (visited[nx][ny].color == 'R' && qInfo.color == 'G' ||
                    visited[nx][ny].color == 'G' && qInfo.color == 'R')) {
                visited[nx][ny].color = 'F';
                answerBuf++;
            }
        }
    }

    if (answerBuf > answer)
        answer = answerBuf;
}

void selectForGreen(int cur, int depth) {
    if (depth == G) {
        countFlowers();
        return;
    }

    for (int i = cur; i < soil.size(); i++) {
        if (soilVisited[i] == 0) {
            soilVisited[i] = 2;
            selectForGreen(i + 1, depth + 1);
            soilVisited[i] = 0;
        }
    }
}

void selectForRed(int cur, int depth) {
    if (depth == R) {
        selectForGreen(0, 0);
        return;
    }

    for (int i = cur; i < soil.size(); i++) {
        if (soilVisited[i] == 0) {
            soilVisited[i] = 1;
            selectForRed(i + 1, depth + 1);
            soilVisited[i] = 0;
        }
    }
}

void solution() {
    selectForRed(0, 0);
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
