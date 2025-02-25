#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> board;
int answer;

void input() {
    cin >> n >> m;
    board = vector(n + 1, vector(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        string inp;
        cin >> inp;
        for (int j = 1; j <= m; j++) {
            board[i][j] = inp[j - 1] - '0';
        }
    }
}

void solution() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j] == 1) {
                board[i][j] = min({board[i][j - 1], board[i - 1][j], board[i - 1][j - 1]}) + 1;
                if (board[i][j] > answer)
                    answer = board[i][j];
            }
        }
    }
}

void output() {
    cout << answer * answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
