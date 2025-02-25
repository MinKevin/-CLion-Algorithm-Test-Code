#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> board;
vector<int> dp;
int answer;

void input() {
    cin >> N;
    board = vector(N, -1);
    dp = vector(N, -1);

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
}

void solution() {
    for (int i = 0; i < N; i++) {
        int max = board[i];
        for (int j = i - 1; j >= 0; j--) {
            if (board[i] > board[j] && dp[j] + board[i] > max)
                max = dp[j] + board[i];
        }
        dp[i] = max;
        if (max > answer)
            answer = max;
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
