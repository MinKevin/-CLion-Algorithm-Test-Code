#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_SIZE 100000

using namespace std;

int T;
int N;
vector<vector<vector<int> > > board;
vector<vector<vector<int> > > dp;
vector<int> answers;

void input() {
    cin >> T;
    board = vector(T, vector<vector<int> >(2));
    dp = vector(T, vector(3, vector<int>(MAX_SIZE, -1)));

    int inp;
    for (int t = 0; t < T; t++) {
        cin >> N;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < N; j++) {
                cin >> inp;
                board[t][i].push_back(inp);
            }
        }
    }
}

int dpFunction(int t, int row, int column) {
    if (dp[t][row][column] != -1)
        return dp[t][row][column];

    if (row == 0) {
        return dp[t][row][column] =
               max(dpFunction(t, 1, column - 1) + board[t][row][column],
                   dpFunction(t, 1, column - 2) + board[t][row][column]);
    }
    if (row == 1) {
        return dp[t][row][column] =
               max(dpFunction(t, 0, column - 1) + board[t][row][column],
                   dpFunction(t, 0, column - 2) + board[t][row][column]);
    }
}

// dp의 row 0:위 선택 1:아래 선택 2:선택x
// dp[0][a] = max(dp[1][a-1], dp[2][a-1])
void solution() {
    for (int t = 0; t < T; t++) {
        dp[t][0][0] = board[t][0][0];
        dp[t][1][0] = board[t][1][0];
        dp[t][0][1] = board[t][1][0] + board[t][0][1];
        dp[t][1][1] = board[t][0][0] + board[t][1][1];

        answers.push_back(max(dpFunction(t, 0, board[t][0].size() - 1), dpFunction(t, 1, board[t][0].size() - 1)));
    }
}

void output() {
    for (int answer: answers)
        cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
