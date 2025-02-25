#include <sstream>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct sequenceInfo {
    int length;
    int from;
};

int N;
vector<int> board;
vector<sequenceInfo> dp;
sequenceInfo answer;

void input() {
    cin >> N;
    board = vector(N, 0);
    dp = vector<sequenceInfo>(N , {-1, -1});

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    answer = {0, 0};
}

void solution() {
    for (int i = 0; i < N; i++) {
        sequenceInfo maxSequence = {1, i};
        for (int j = i - 1; j >= 0; j--) {
            if (board[i] > board[j] && maxSequence.length < dp[j].length + 1)
                maxSequence = {dp[j].length + 1, j};
        }
        dp[i] = maxSequence;

        if (answer.length < dp[i].length) {
            answer = {dp[i].length, i};
        }
    }
}

void output() {
    cout << answer.length << '\n';
    stack<int> s;

    sequenceInfo cur = answer;
    do {
        s.push(board[cur.from]);
        cur = dp[cur.from];
    } while (cur.length > 1);

    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();

    solution();

    output();
}
