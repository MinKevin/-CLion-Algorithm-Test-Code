#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int M, N;
vector<vector<int>> board;
vector<vector<int>> visited;

void input() {
    cin >> M >> N;

    board = vector(M, vector<int>(N));
    visited = vector(M, vector(N, -1));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
}

int dfs(int x, int y) {
    if (visited[x][y] != -1)
        return visited[x][y];

    visited[x][y] = 0;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= M || ny >= N)
            continue;

        if (board[x][y] > board[nx][ny]) {
            visited[x][y] += dfs(nx, ny);
        }
    }

    return visited[x][y];
}

void solution() {
    visited[M - 1][N - 1] = 1;
}

void output() {
    cout << dfs(0, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
