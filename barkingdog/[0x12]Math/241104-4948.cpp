#include <sstream>
#include <iostream>
#include <vector>

#define MAX_NUM (123456 * 2)

using namespace std;

vector<int> N;
vector<int> board;
vector<int> dp;
vector<int> answers;

void input() {
    int n;
    board = vector(MAX_NUM + 1, 0);
    dp = vector(MAX_NUM + 1, 0);

    while (true) {
        cin >> n;
        if (n == 0)
            break;
        N.push_back(n);
    }
}

void solution() {
    for (int i = 1; i <= MAX_NUM; i++) {
        board[i] = i;
    }

    int count = 0;
    for (int i = 2; i <= MAX_NUM; i++) {
        if (board[i] != -1) {
            count++;
            for (int j = 2; i * j <= MAX_NUM; j++) {
                board[i * j] = -1;
            }
        }

        dp[i] = count;
    }

    for (int i = 0; i < N.size(); i++) {
        answers.push_back(dp[N[i] * 2] - dp[N[i]]);
    }
}

void output() {
    for (int answer : answers)
        cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
