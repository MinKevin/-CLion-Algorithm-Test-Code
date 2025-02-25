#include <sstream>
#include <iostream>
#include <vector>
#define MAX_NUM 1000000

using namespace std;

int n;
vector<vector<vector<int>>> board;
vector<vector<vector<int>>> dp;
vector<int> answers;

void input() {
    int test = 0;
    while (true) {
        cin >> n;
        if (n == 0)
            break;
        dp.push_back(vector(n, vector(3, MAX_NUM)));
        board.push_back(vector(n, vector(3, 0)));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> board[test][i][j];
            }
        }
        test++;
    }

}

int dpFunction(int test, int row, int column) {
    if (dp[test][row][column] != MAX_NUM)
        return dp[test][row][column];

    int minCost = MAX_NUM;
    if (row >= 1)
        minCost = min(dpFunction(test, row - 1, column), minCost);
    if (column >= 1)
        minCost = min(dpFunction(test, row, column - 1), minCost);
    if (row >= 1 && column >= 1)
        minCost = min(dpFunction(test, row - 1, column - 1), minCost);
    if (row >= 1 && column <= 1)
        minCost = min(dpFunction(test, row - 1, column + 1), minCost);

    return dp[test][row][column] = minCost + board[test][row][column];
}

void solution() {
    for (int t = 0; t < dp.size(); t++) {
        dp[t][0][1] = board[t][0][1];
        answers.push_back(dpFunction(t, dp[t].size() - 1, 1));
    }

}

void output() {
    for (int i = 1; i <= answers.size(); i++) {
        cout << i << ". " << answers[i - 1] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
