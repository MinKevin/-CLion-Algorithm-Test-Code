#include <sstream>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<vector<char> > board(5, vector<char>(5));
vector<vector<bool> > visited(5, vector<bool>(5, false));
int answer;

void input() {
    string inp;
    for (int i = 0; i < 5; i++) {
        cin >> inp;
        for (int j = 0; j < 5; j++) {
            board[i][j] = inp[j];
        }
    }
    answer = 0;
}

bool isAdjacent(pair<int, int> startLoc) {
    vector<vector<bool> > visitedForBFS(5, vector<bool>(5, false));
    queue<pair<int, int> > q;
    q.push(startLoc);
    visitedForBFS[startLoc.first][startLoc.second] = true;
    int length = 1;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
                continue;

            if (visited[nx][ny] == 1 && visitedForBFS[nx][ny] == false) {
                length++;
                visitedForBFS[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    if (length == 7)
        return true;
    return false;
}

void dfs(pair<int, int> startLoc, int SCnt, int YCnt) {
    if (SCnt + YCnt == 7) {
        pair<int, int> exLoc = (startLoc.second == 0 ? make_pair(startLoc.first - 1, 4) : make_pair(startLoc.first, startLoc.second - 1));
        if (isAdjacent(exLoc))
            answer++;
        return;
    }

    for (int i = startLoc.first; i < 5; i++) {
        int j = 0;
        if (i == startLoc.first)
            j = startLoc.second;
        for (; j < 5; j++) {
            if (board[i][j] == 'S') {
                visited[i][j] = true;
                pair<int, int> nextLoc = (j + 1) < 5 ? make_pair(i, j + 1) : make_pair(i + 1, 0);
                dfs(nextLoc, SCnt + 1, YCnt);
                visited[i][j] = false;
            }
            else if (board[i][j] == 'Y' && YCnt < 3) {
                visited[i][j] = true;
                pair<int, int> nextLoc = (j + 1) < 5 ? make_pair(i, j + 1) : make_pair(i + 1, 0);
                dfs(nextLoc, SCnt, YCnt + 1);
                visited[i][j] = false;
            }
        }
    }

}

void solution() {
    dfs({0, 0}, 0, 0);
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
